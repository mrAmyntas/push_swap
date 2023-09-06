/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:31:11 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 19:38:35 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static int	ft_check_intmax_min(long long unsigned int n,
	int i, char *str, int x)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + str[i] - 48;
		i++;
	}
	if (x == 1)
	{
		if ((n - 1) > INT_MAX)
			return (-1);
	}
	else
	{
		if (n > INT_MAX)
			return (-1);
	}
	return (0);
}

static int	ft_onlynum2(char *str, int i, int n)
{
	if (i == 0)
	{
		i = ft_check_intmax_min(n, i, str, 0);
		if (i < 0)
			return (-1);
	}
	if (i == 1)
	{
		i = ft_check_intmax_min(n, i, str, 1);
		if (i < 0)
			return (-1);
	}
	return (0);
}

static int	ft_onlynum(char *str)
{
	int						i;
	long long unsigned int	n;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	i = 0;
	n = 0;
	if (str[i] == '-')
		i++;
	i = ft_onlynum2(str, i, n);
	return (i);
}

int	ft_check_array(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = ft_onlynum(argv[i]);
		if (j < 0)
			return (-1);
		if (i > 1)
		{
			j = i;
			while (j > 1)
			{
				if (!(ft_strncmp(argv[i], argv[j - 1], 1000)))
					return (-1);
				j--;
			}
		}
		i++;
	}
	return (0);
}

int	*ft_make_int_array(char **numbers, int len)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * (len));
	if (array == NULL)
		return (NULL);
	i = 1;
	while (len > 0)
	{
		array[i - 1] = ft_atoi(numbers[i]);
		i++;
		len--;
	}
	return (array);
}
