/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   operations3.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 16:56:31 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/22 17:25:54 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

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
}

void	ft_operation_rr(t_data *data)
{
	ft_operation_ra(data);
	ft_operation_rb(data);
}

void	ft_operation_rrr(t_data *data)
{
	ft_operation_rra(data);
	ft_operation_rrb(data);
}
