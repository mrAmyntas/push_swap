/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strrchr.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: basz <basz@student.codam.nl>                 +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/28 15:44:20 by basz          #+#    #+#                 */
/*   Updated: 2021/10/22 16:37:25 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	j;

	i = ft_strlen(s);
	j = 0;
	while (j <= i)
	{
		if (s[i] == c)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
