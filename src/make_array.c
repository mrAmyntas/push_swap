/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   make_array.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/10/27 13:31:11 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 15:07:54 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_check_intmax_min(long long unsigned int n,
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
			ft_error();
	}
	else
	{
		if (n > INT_MAX)
			ft_error();
	}
}

static void	ft_onlynum(char *str)
{
	int						i;
	long long unsigned int	n;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			ft_error();
		i++;
	}
	i = 0;
	n = 0;
	if (str[i] == '-')
		i++;
	if (i == 0)
		ft_check_intmax_min(n, i, str, 0);
	if (i == 1)
		ft_check_intmax_min(n, i, str, 1);
}

void	ft_check_array(char **argv, int x)
{
	int	i;
	int	j;

	i = 1;
	if (x == 0)
		i = 0;
	while (argv[i] != NULL)
	{
		ft_onlynum(argv[i]);
		if (i > 1)
		{
			j = i;
			while (j > 1)
			{
				if (!(ft_strncmp(argv[i], argv[j - 1], 1000)))
					ft_error();
				j--;
			}
		}
		i++;
	}
}

int	*ft_make_int_array(char **numbers, int len, int x)
{
	int	i;
	int	*array;

	array = (int *)malloc(sizeof(int) * len);
	i = 0;
	while (len > 0)
	{
		array[i] = ft_atoi(numbers[i + x]);
		i++;
		len--;
	}
	return (array);
}

int	ft_array_size(char **numbers, int x)
{
	int	i;

	i = 1;
	if (x == 0)
		i = 0;
	while (numbers[i] != NULL)
		i++;
	if (x == 0)
		return (i);
	return (i - 1);
}
