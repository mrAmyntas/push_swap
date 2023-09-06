/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/16 13:32:09 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/10/22 21:21:02 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//sets the first 2 positions (a,b) of the lowest numbers of the stack
//so for 1 5 4 3 it would be a=0 and b=3
void	ft_set_pos(t_positions *positions, t_data *data, int size)
{
	positions->a = 0;
	positions->b = 0;
	positions->x = data->stack_a_len / 2;
	while ((data->ranking[data->i] != data->stack_a[positions->a])
		&& data->stack_a_len > 0)
		positions->a++;
	while ((data->ranking[data->i + 1] != data->stack_a[positions->b])
		&& (data->i + 1 <= data->m_len) && positions->b < data->stack_a_len)
		positions->b++;
	if (size > 0)
		data->chunk = (int **)malloc(sizeof(int *)
				* ((data->stack_a_len / size) + 1));
}

//Creates the chunks. If input is 100 numbers, chunksize would be 20, so here 5 chunks are made
//with chunk 0 being the highest 20 numbers, then the next 20 highest in the next etc.
//Lets say input is 105 numbers, the last chunk is only 5 big. 
int	ft_chunk(t_data *data, int size, int i, int j)
{
	while (j < (data->m_len / size))
	{
		i = 0;
		data->chunk[j] = (int *)malloc(sizeof(int) * size);
		while (i < size)
		{
			data->chunk[j][i] = data->ranking[i + (j * size)];
			i++;
		}
		j++;
	}
	if (data->stack_a_len != j * size)
	{
		data->chunk[j] = (int *)malloc(sizeof(int)
				* (data->m_len - (j * size)));
		i = 0;
		while (i < (data->m_len - (j * size)))
		{
			data->chunk[j][i] = data->ranking[i + (j * size)];
			i++;
		}
		return (j + 1);
	}
	return (j);
}

int	ft_check_b(t_data *data, int a)
{
	int	i;

	i = 0;
	while (data->stack_b[i] < data->stack_a[a] && i < data->stack_b_len)
		i++;
	if (i == data->stack_b_len && data->stack_b[i - 1] < data->stack_a[a])
		return (1);
	i = 0;
	while (data->stack_b[i] > data->stack_a[a] && i < data->stack_b_len)
		i++;
	if (i == data->stack_b_len && data->stack_b[i - 1] > data->stack_a[a])
		return (2);
	return (0);
}

void	ft_reset_b(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while ((j + i) < data->stack_b_len)
	{
		if (data->stack_b[i] < data->stack_b[i + j])
		{
			i = i + j;
			j = 1;
		}
		else
			j++;
	}
	ft_rotate_to_top(data, i, (data->stack_b_len / 2));
}

//rotates b times, left or right dependin on which is closer
void	ft_rotate_push(t_positions *pos, t_data *data, int b)
{
	if (b <= pos->x)
		ft_rotate_left(data, b);
	else
		ft_rotate_right(data, b);
	ft_operation_pb(data);
}
