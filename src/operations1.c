/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations1.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:36:26 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 15:10:32 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_operation_sa(t_data *data)
{
	int	store;

	if (data->stack_a_len > 1)
	{
		store = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = store;
	}
	write(1, "sa\n", 3);
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
	write(1, "sb\n", 3);
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
	data->i--;
	write(1, "pa\n", 3);
}

void	ft_operation_pb(t_data *data)
{
	int	i;

	i = data->stack_b_len - 1;
	if (data->stack_a_len > 0)
	{
		while (i > -1)
		{
			data->stack_b[i + 1] = data->stack_b[i];
			i--;
		}
		data->stack_b[0] = data->stack_a[0];
		data->stack_b_len++;
		i = 1;
		while (i < data->stack_a_len)
		{
			data->stack_a[i - 1] = data->stack_a[i];
			i++;
		}
		data->stack_a_len--;
	}
	write(1, "pb\n", 3);
	data->i++;
}

int	ft_check_a(t_data *data)
{
	int	i;

	i = 0;
	while (i < (data->stack_a_len - 1))
	{
		if (data->stack_a[i] > data->stack_a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
