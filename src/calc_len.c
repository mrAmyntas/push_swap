/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   calc_len.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/09 13:20:11 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/10/22 21:33:22 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//positions->x is the middle
//so x is the distance a is from middle and y for b
//thus it returns 1 if b is closest to middle/furthest from top/bot of stack)
//or 0 vice versa
int	ft_calc_len_from_mid(t_positions *positions, int a, int b)
{
	int	x;
	int	y;

	x = a - positions->x;
	if (x < 0)
		x = x * -1;
	y = b - positions->x;
	if (y < 0)
		y = y * -1;
	if (x > y)
		return (1);
	else
		return (0);
}


// int	ft_calc_len_from_mid(t_positions *positions, int x, int y)
// {
// 	int	a;
// 	int	b;

// 	a = x - positions->x;
// 	if (a < 0)
// 		a = a * -1;
// 	b = y - positions->x;
// 	if (b < 0)
// 		b = b * -1;
// 	if (a > b)
// 		return (1);
// 	else
// 		return (0);
// }


static void	ft_swap(t_data *data, int i)
{
	int	store;

	store = data->ranking[i];
	data->ranking[i] = data->ranking[i + 1];
	data->ranking[i + 1] = store;
}

//constructs the ranking array. This array takes all the numbers in stack a
//and sorts them from small to big
void	ft_small_to_big(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->stack_a_len)
	{
		data->ranking[i] = data->stack_a[i];
		i++;
	}
	i = 0;
	while ((i + 1) < data->stack_a_len)
	{
		if (data->ranking[i] > data->ranking[i + 1])
		{
			ft_swap(data, i);
			j = i;
			while ((j > 0) && (data->ranking[j] < data->ranking[j - 1]))
			{
				ft_swap(data, (j - 1));
				j--;
			}
		}
		i++;
	}
}
