/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:15:25 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/10 13:10:03 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#include <stdio.h>

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

int	main(int ac, char **av)
{
	int			i;
	char		*map;
	char		**board;
	t_map_info	info;

	i = 1;
	while (i < ac)
	{
		map = get_map(av[i]);
		if (!map)
			return (1);
		info = get_first_line_info(map);
		board = get_board(info, map);
		if (!board)
			return (1);
		i++;
		printf("Empty = %c\nObstacle = %c\nFill = %c\nRows = %d\nCols = %d\n",
			info.empty, info.obstacle, info.fill, info.x, info.y);
		board = solve(board, &info);
		print_board(board, info);
		free(map);
		if (board)
			free_board(info, board);
	}
}
