/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 15:50:52 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/10 16:49:17 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

char	**allocate_board(t_map_info info, char **board)
{
	int	row;

	board = (char **) malloc((info.x + 1) * sizeof(char *));
	if (!board)
		return (NULL);
	row = 0;
	while (row < info.x)
	{
		board[row] = (char *) malloc((info.y + 1) * sizeof(char));
		if (!board[row])
		{
			free_board(info, board);
			return (NULL);
		}
		row++;
	}
	return (board);
}

char	**make_board(t_map_info info, char **board, char *map)
{
	int	i;
	int	j;
	int	row;

	i = 0;
	row = 0;
	while (map[i] != '\n')
		i++;
	i++;
	while (row < info.x)
	{
		j = 0;
		while (j < info.y && map[i] != '\n')
			board[row][j++] = map[i++];
		if ((j < info.y && map[i] == '\n') || (j == info.y && map[i] != '\n'))
		{
			write(1, "map error\n", 10);
			return (NULL);
		}
		board[row++][j] = 0;
		i++;
	}
	board[row] = NULL;
	return (board);
}

char	**check_chars(t_map_info info, char **board)
{
	int	i;
	int	j;

	i = 0;
	while (i < info.x)
	{
		j = 0;
		while (board[i][j])
		{
			if (board[i][j] != info.empty && board[i][j] != info.obstacle)
			{
				write(1, "map error\n", 10);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	return (board);
}

char	**get_board(t_map_info info, char *map)
{
	char	**board;
	char	**verif;

	board = NULL;
	board = allocate_board(info, board);
	if (!board)
		return (NULL);
	verif = make_board(info, board, map);
	if (!verif)
	{
		free_board(info, board);
		return (NULL);
	}
	verif = check_chars(info, verif);
	if (!verif)
	{
		free_board(info, board);
		return (NULL);
	}
	return (verif);
}
