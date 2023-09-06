/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sort_chunks.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/17 12:47:20 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/10/22 21:56:56 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//scans the stack from the top and finds the first occurence of a number
//which is also in the chunk. It returns the position of this number.
//If no members of the chunk are left in the stack, it returns -1
static int	ft_scan_top(t_data *data, int chunk, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->stack_a_len)
	{
		j = 0;
		while ((data->stack_a[i] != data->chunk[chunk][j]) && (j < size))
			j++;
		if ((j == size) && (data->stack_a[i] != data->chunk[chunk][j - 1]))
			i++;
		else
			return (i);
	}
	return (-1);
}

//scans the stack from the bottom and finds the first occurence of a number
//which is also in the chunk. It returns the position of this number.
//If no members of the chunk are left in the stack, it returns -1
static int	ft_scan_bot(t_data *data, int chunk, int size)
{
	int	i;
	int	j;

	i = data->stack_a_len - 1;
	while (i >= 0)
	{
		j = 0;
		while ((data->stack_a[i] != data->chunk[chunk][j]) && (j < size))
			j++;
		if ((j == size) && (data->stack_a[i] != data->chunk[chunk][j - 1]))
			i--;
		else
			return (i);
	}
	return (-1);
}

//finds the right spot to push to stack b. Stack b is going to be rotated so that
//the number that is coming from a, is pushed in the right spot (the closest smaller number and the closest bigger number)
static void	ft_findspot(t_data *data, int a)
{
	int	i;

	if (data->stack_b_len < 2)
		return ;
	i = ft_check_b(data, a);
	if (i != 0)
		ft_reset_b(data);
	else
		ft_rb_or_rrb(data, a, 0, 0);
}

static void	ft_find_rotate(t_data *data, t_positions *pos, int a)
{
	ft_findspot(data, a);
	ft_rotate_push(pos, data, a);
	if (data->stack_b[0] < data->stack_b[1] && data->stack_b_len == 2)
		ft_operation_sb(data);
}

void	ft_sort_chunks(t_data *data, int size, int a, int b)
{
	int			i;
	int			chunk;
	t_positions	pos;

	ft_set_pos(&pos, data, size);
	i = ft_chunk(data, size, 0, 0);
	chunk = 0;
	while (i > 0)
	{
		a = ft_scan_top(data, chunk, size);
		b = ft_scan_bot(data, chunk, size);
		if (a == -1)
		{
			i--;
			chunk++;
			continue ;
		}
		if (ft_calc_len_from_mid(&pos, a, b) || a == b)
			ft_find_rotate(data, &pos, a);
		else
			ft_find_rotate(data, &pos, b);
	}
	ft_rotate_b_back(data, 0);
}
