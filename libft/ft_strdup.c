/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/03 13:19:51 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 16:34:01 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buff;
	int		l;
	int		i;

	l = ft_strlen(s1);
	buff = malloc((l + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		buff[i] = s1[i];
		i++;
	}
	buff[i] = '\0';
	return (buff);
}
