/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   simple.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/10 16:05:04 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/10/22 21:23:10 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//after last push, the position of the next number shifted, so needs
//to be adjusted
static int adjusted_pos(t_data *data, int b, int a, int x)
{
	if (a <= x)
		b -= a;
	else
		b += (data->stack_a_len - a + 1);
	b--;
	return (b);
}

static void	ft_simple4(t_data *data)
{
	t_positions	positions;

	ft_set_pos(&positions, data, 0);
	ft_rotate_push(&positions, data, positions.a);
	if (ft_check_a(data) == 1)
		ft_simple(data, 1);
	ft_operation_pa(data);
}

static void	ft_simple5(t_data *data)
{
	t_positions	pos;

	ft_set_pos(&pos, data, 0);
	if (ft_calc_len_from_mid(&pos, pos.a, pos.b))
	{
		ft_rotate_push(&pos, data, pos.a);
		ft_rotate_push(&pos, data, adjusted_pos(data, pos.b, pos.a, pos.x));
		if (ft_check_a(data) == 1)
			ft_simple(data, 2);
		while (data->stack_b_len > 0)
			ft_operation_pa(data);
	}
	else
	{
		ft_rotate_push(&pos, data, pos.b);
		ft_rotate_push(&pos, data, adjusted_pos(data, pos.a, pos.b, pos.x));
		if (ft_check_a(data) == 1)
			ft_simple(data, 2);
		ft_operation_pa(data);
		ft_operation_pa(data);
		ft_operation_sa(data);
	}
}

static void	ft_simple3(t_data *data, int x)
{
	if (data->stack_a[0] == data->ranking[0 + x])
	{
		ft_operation_rra(data);
		ft_operation_sa(data);
	}
	else if (data->stack_a[0] == data->ranking[1 + x]
		&& data->stack_a[1] == data->ranking[0 + x])
		ft_operation_sa(data);
	else if (data->stack_a[0] == data->ranking[1 + x]
		&& data->stack_a[1] == data->ranking[2 + x])
		ft_operation_rra(data);
	else if (data->stack_a[0] == data->ranking[2 + x]
		&& data->stack_a[1] == data->ranking[0 + x])
		ft_operation_ra(data);
	else
	{
		ft_operation_ra(data);
		ft_operation_sa(data);
	}
}

//for 2-5 numbers this simple algorithm is used
//for 5: push 2 smallsest to stack b, then sort a, swap b if neccesary and push back to a
//for 4: same as 5 but only push smallest to b
//for 3: hardcode the most optimal way
void	ft_simple(t_data *data, int x)
{
	if (data->stack_a_len == 2)
		ft_operation_sa(data);
	if (data->stack_a_len == 3)
		ft_simple3(data, x);
	else if (data->stack_a_len == 4)
		ft_simple4(data);
	else if (data->stack_a_len == 5)
		ft_simple5(data);
}
