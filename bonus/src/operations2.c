/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations2.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 19:21:33 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 16:50:27 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	ft_operation_ra(t_data *data)
{
	int	i;
	int	store;

	if (data->stack_a_len > 1)
	{
		store = data->stack_a[0];
		i = 1;
		while (i < data->stack_a_len)
		{	
			data->stack_a[i - 1] = data->stack_a[i];
			i++;
		}
		data->stack_a[i - 1] = store;
	}
}

void	ft_operation_rb(t_data *data)
{
	int	i;
	int	store;

	if (data->stack_b_len > 1)
	{
		store = data->stack_b[0];
		i = 1;
		while (i < data->stack_b_len)
		{	
			data->stack_b[i - 1] = data->stack_b[i];
			i++;
		}
		data->stack_b[i - 1] = store;
	}
}

void	ft_operation_rra(t_data *data)
{
	int	i;
	int	store;

	if (data->stack_a_len > 1)
	{
		store = data->stack_a[data->stack_a_len - 1];
		i = data->stack_a_len - 1;
		while (i > 0)
		{	
			data->stack_a[i] = data->stack_a[i - 1];
			i--;
		}
		data->stack_a[0] = store;
	}
}

void	ft_operation_rrb(t_data *data)
{
	int	i;
	int	store;

	if (data->stack_b_len > 1)
	{
		store = data->stack_b[data->stack_b_len - 1];
		i = data->stack_b_len - 1;
		while (i > 0)
		{	
			data->stack_b[i] = data->stack_b[i - 1];
			i--;
		}
		data->stack_b[0] = store;
	}
}

void	ft_operation_ss(t_data *data)
{
	int	store;

	if (data->stack_a_len > 1)
	{
		store = data->stack_a[0];
		data->stack_a[0] = data->stack_a[1];
		data->stack_a[1] = store;
	}
	if (data->stack_b_len > 1)
	{
		store = data->stack_b[0];
		data->stack_b[0] = data->stack_b[1];
		data->stack_b[1] = store;
	}
}
