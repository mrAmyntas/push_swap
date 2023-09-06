/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   rotate.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 19:16:05 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 15:01:04 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_rotate_left(t_data *data, int i)
{
	while (i > 0)
	{
		ft_operation_ra(data);
		i--;
	}
}

void	ft_rotate_right(t_data *data, int i)
{
	while (i < data->stack_a_len)
	{
		ft_operation_rra(data);
		i++;
	}
}

void	ft_rotate_b_back(t_data *data, int i)
{
	if (data->stack_b[0] < data->stack_b[1])
	{
		ft_operation_rb(data);
		return ;
	}
	while (data->stack_b[i] > data->stack_b[i + 1])
		i++;
	if (i > (data->stack_b_len / 2))
	{
		while (i < (data->stack_b_len - 1))
		{
			ft_operation_rrb(data);
			i++;
		}
	}
	else
	{
		i++;
		while (i > 0)
		{
			ft_operation_rb(data);
			i--;
		}
	}
}

void	ft_rb_or_rrb(t_data *data, int a, int i, int j)
{
	while (i < data->stack_b_len && data->stack_a[a] > data->stack_b[i])
		i++;
	while (data->stack_a[a] < data->stack_b[i + j]
		&& (i + j) < data->stack_b_len)
		j++;
	if ((i + j) > (data->stack_b_len / 2))
	{
		while ((i + j) < data->stack_b_len)
		{
			ft_operation_rrb(data);
			i++;
		}
	}
	else
	{
		while ((i + j) > 0)
		{
			ft_operation_rb(data);
			i--;
		}
	}
}

void	ft_rotate_to_top(t_data *data, int i, int x)
{
	if (i > x)
	{
		while (i < data->stack_b_len)
		{
			ft_operation_rrb(data);
			i++;
		}
	}
	else
	{
		while (i > 0)
		{
			ft_operation_rb(data);
			i--;
		}
	}
}
