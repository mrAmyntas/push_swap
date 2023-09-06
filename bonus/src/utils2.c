/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 17:10:51 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/23 13:13:54 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_check_order(t_data *data)
{
	int	i;

	i = data->stack_a_len - 1;
	while (i > 0)
	{
		if (data->stack_a[i - 1] > data->stack_a[i])
		{
			write(2, "KO\n", 3);
			return ;
		}
		i--;
	}
	if (data->stack_b_len != 0)
	{
		write(2, "KO\n", 3);
		return ;
	}
	write(2, "OK\n", 3);
}

int	ft_check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' && line[i + 1] == ' ')
			return (-1);
		if (line[i] == ' ' && i == 0)
			return (-1);
		if (line[i] == ' ' && line[i + 1] == '\0')
			return (-1);
		i++;
	}
	return (0);
}

void	ft_error(char *line, char **array, t_data *data, int x)
{
	write(2, "Error\n", 6);
	free(data->stack_a);
	free(data->stack_b);
	if (array != NULL)
		free(array);
	if (x == 1)
		free(line);
	exit(1);
}

int	ft_array_size(char **numbers)
{
	int	i;

	i = 1;
	while (numbers[i] != NULL)
		i++;
	return (i - 1);
}
