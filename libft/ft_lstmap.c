/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 16:30:31 by basz          #+#    #+#                 */
/*   Updated: 2021/10/22 16:29:18 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(t_list *startlist)
{
	t_list	*to_free;

	while (startlist != NULL)
	{
		to_free = startlist;
		startlist = startlist->next;
		free(to_free->content);
		free(to_free);
	}
	return (NULL);
}

static t_list	*ft_lstnewelem(void *content)
{
	t_list	*new;

	if (content == NULL)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
	{
		free(new->content);
		return (NULL);
	}
	new->content = content;
	new->next = NULL;
	return (new);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newelem;
	t_list	*newlist;
	t_list	*startlist;

	if (lst == NULL)
		return (NULL);
	newelem = ft_lstnewelem(f(lst->content));
	if (newelem == NULL)
		return (NULL);
	newlist = newelem;
	startlist = newlist;
	lst = lst->next;
	while (lst != NULL)
	{
		newelem = ft_lstnewelem(f(lst->content));
		if (newelem == NULL)
			return (ft_free(startlist));
		newlist->next = newelem;
		newlist = newelem;
		lst = lst->next;
	}
	if (startlist->content == NULL)
		del(newlist->content);
	return (startlist);
}
