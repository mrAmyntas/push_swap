/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   push_swap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 15:18:04 by bhoitzin      #+#    #+#                 */
/*   Updated: 2022/10/22 18:05:28 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	ft_free2(t_data *data, char **argv)
{
	int	i;

	i = 0;
	while (i < (data->stack_a_len / 42) && data->m_len >= 350)
	{
		free(data->chunk[i]);
		i++;
	}
	if (data->m_len != i * 42 && data->m_len >= 350)
		free(data->chunk[i]);
	if (data->m_len >= 350)
		free(data->chunk);
	if (data->x == 0)
	{
		i = 0;
		while (argv[i] != NULL)
		{
			free(argv[i]);
			i++;
		}
		free(argv);
	}
}

static void	ft_free(t_data *data, char **argv)
{
	int	i;

	free(data->stack_a);
	free(data->stack_b);
	free(data->array);
	free(data->ranking);
	i = 0;
	while (i < (data->stack_a_len / 20)
		&& (data->m_len >= 6 && data->m_len < 350))
	{
		free(data->chunk[i]);
		i++;
	}
	if (data->m_len != i * 20 && (data->m_len >= 6 && data->m_len < 350))
		free(data->chunk[i]);
	if (data->m_len >= 6 && data->m_len < 350)
		free(data->chunk);
	ft_free2(data, argv);
}

static void	ft_set_struct(t_data *data, char **argv)
{
	data->stack_b_len = 0;
	data->i = 0;
	ft_check_array(argv, data->x);
	data->stack_a_len = ft_array_size(argv, data->x);
	data->stack_a = ft_make_int_array(argv, data->stack_a_len, data->x);
	data->stack_b = (int *)malloc(sizeof(int) * data->stack_a_len);
	data->ranking = (int *)malloc(sizeof(int) * data->stack_a_len);
	data->array = (int *)malloc(sizeof(int) * 5);
	data->m_len = data->stack_a_len;
	ft_bzero(data->stack_b, data->stack_a_len);
	ft_bzero(data->ranking, data->stack_a_len);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

//the input is stored in stack a. Depending on the size of the input,
//the stack is sorted either with a simple algorithm (hardcoded for < 6)
//or sorted with the ft_sort_chunks which segments the stack in chunks of 
//20 numbers for medium sized input or 42 numbers for large inputs (the 20 largests numbers would be a chunk)
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2)
		return (0);
	data.x = 1;
	if (argc == 2)
	{
		argv = ft_split(argv[1], ' ');
		data.x = 0;
	}
	ft_set_struct(&data, argv);
	if (ft_check_a(&data) == 0)
		return (0);
	ft_small_to_big(&data);
	if (data.stack_a_len >= 350)
		ft_sort_chunks(&data, 42, 0, 0);
	else if (data.stack_a_len >= 6 && data.stack_a_len < 350)
		ft_sort_chunks(&data, 20, 0, 0);
	else if (data.stack_a_len < 6)
		ft_simple(&data, 0);
	while (data.stack_b_len > 0)
		ft_operation_pa(&data);
	ft_free(&data, argv);
	return (0);
}
