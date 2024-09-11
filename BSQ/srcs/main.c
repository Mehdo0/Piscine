/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:25 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/11 14:51:17 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	free_board(t_map_info info, char **board)
{
	int	i;

	i = 0;
	while (i < info.x)
	{
		if (!board[i])
			return ;
		free(board[i]);
		i++;
	}
	if (!board)
		return ;
	free(board);
}

void	map_given(char *str)
{
	char		*map;
	char		**board;
	t_map_info	info;

	map = get_map(str, 1);
	if (!map)
		return ;
	info = get_first_line_info(map);
	if (info.x == 0 || info.y == 0)
		return ;
	board = get_board(info, map);
	if (!board)
		return ;
	board = solve(board, &info);
	print_board(board, info);
	write(1, "\n", 1);
	free(map);
	if (board)
		free_board(info, board);
	return ;
}

void	no_map_given(void)
{
	char		*map;
	char		*str;
	char		**board;
	t_map_info	info;

	str = 0;
	map = get_map(str, 0);
	if (!map)
		return ;
	info = get_first_line_info(map);
	if (info.x == 0 || info.y == 0)
		return ;
	board = get_board(info, map);
	if (!board)
		return ;
	board = solve(board, &info);
	print_board(board, info);
	write(1, "\n", 1);
	free(map);
	if (board)
		free_board(info, board);
	return ;
}

char	**low_solve(char **board, t_map_info *info)
{
	int	i;
	int	j;

	if (low_density(board, info) == 1)
	{
		i = 0;
		while (i < info->x)
		{
			j = 0;
			while (j < info->y)
			{
				board[i][j] = info->fill;
				j++;
			}
			i++;
		}
	}
	return (board);
}

int	main(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		map_given(av[i]);
		i++;
	}
	if (ac == 1)
		no_map_given();
	return (0);
}
