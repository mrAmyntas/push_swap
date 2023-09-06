/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:36:26 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/23 13:04:16 by basz          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_operation_sa(t_data *data)
{
	int	store;

	if (data->stack_a_len > 1)
	{
		store = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = store;
	}
}

void	ft_operation_sb(t_data *data)
{
	int	store;

	if (data->stack_b_len > 1)
	{
		store = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = store;
	}
}

void	ft_operation_pa(t_data *data)
{
	int	i;

	i = data->stack_a_len - 1;
	if (data->stack_b_len > 0)
	{
		while (i > -1)
		{
			data->stack_a[i + 1] = data->stack_a[i];
			i--;
		}
		data->stack_a[0] = data->stack_b[0];
		data->stack_a_len++;
		i = 1;
		while (i < data->stack_b_len)
		{
			data->stack_b[i - 1] = data->stack_b[i];
			i++;
		}
		data->stack_b_len--;
	}
}

static int	ft_operations2(char **array, t_data *data, int i)
{
	if (!(ft_strncmp(array[i], "rra", 3)))
		ft_operation_rra(data);
	else if (!(ft_strncmp(array[i], "rr", 3)))
		ft_operation_rr(data);
	else if (!(ft_strncmp(array[i], "rrb", 3)))
		ft_operation_rrb(data);
	else if (!(ft_strncmp(array[i], "rrr", 3)))
		ft_operation_rrr(data);
	else
		return (-1);
	return (0);
}

int	ft_operations(char **array, t_data *data, int i, int x)
{
	while (array[i] != NULL)
	{
		if (!(ft_strncmp(array[i], "sa", 2)))
			ft_operation_sa(data);
		else if (!(ft_strncmp(array[i], "sb", 3)))
			ft_operation_sb(data);
		else if (!(ft_strncmp(array[i], "ss", 3)))
			ft_operation_ss(data);
		else if (!(ft_strncmp(array[i], "pa", 3)))
			ft_operation_pa(data);
		else if (!(ft_strncmp(array[i], "pb", 3)))
			ft_operation_pb(data);
		else if (!(ft_strncmp(array[i], "ra", 3)))
			ft_operation_ra(data);
		else if (!(ft_strncmp(array[i], "rb", 3)))
			ft_operation_rb(data);
		else
		{
			x = ft_operations2(array, data, i);
			if (x == -1)
				return (x);
		}
		i++;
	}
	return (0);
}
