/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   checker.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: bhoitzin <bhoitzin@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/08 15:18:04 by bhoitzin      #+#    #+#                 */
/*   Updated: 2021/10/24 13:41:04 by bhoitzin      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

static void	ft_freestacks(t_data *data)
{
	free(data->stack_a);
	free(data->stack_b);
}

static void	ft_set_struct(t_data *data, char **argv)
{
	data->stack_a_len = ft_array_size(argv);
	data->stack_b_len = 0;
	data->stack_a = ft_make_int_array(argv, data->stack_a_len);
	if (data->stack_a == NULL)
		exit(1);
	data->stack_b = (int *)malloc(sizeof(int) * data->stack_a_len);
	if (data->stack_b == NULL)
	{
		free(data->stack_a);
		exit(1);
	}
}

static void	ft_exit(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

static int	ft_loop_lines(t_data *data, char *line, char **array)
{
	data->i = get_next_line(&line);
	if (data->i < 0)
		ft_error(line, array, data, 0);
	if (data->i == 0)
	{
		free(line);
		ft_check_order(data);
		return (0);
	}
	array = ft_split(line, ' ');
	if (array == NULL)
		ft_error(line, array, data, 0);
	data->x = ft_check_line(line);
	if (data->x < 0)
		ft_error(line, array, data, 1);
	data->x = ft_operations(array, data, 0, 0);
	if (data->x < 0)
		ft_error(line, array, data, 1);
	ft_freearray_line(array, line, data);
	return (1);
}

int	main(int argc, char **argv)
{
	t_data	data;
	char	*line;
	char	**array;

	line = 0;
	if (argc < 2)
		return (0);
	data.z = ft_check_array(argv);
	if (data.z < 0)
		ft_exit();
	ft_set_struct(&data, argv);
	array = NULL;
	data.z = 1;
	while (data.z == 1)
	{
		data.z = ft_loop_lines(&data, line, array);
		if (data.z < 0)
		{
			ft_freestacks(&data);
			return (1);
		}
	}
	ft_freestacks(&data);
	return (0);
}
