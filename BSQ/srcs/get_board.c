/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_board.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:34:37 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/10 11:01:21 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#include <stdio.h>

void	print_board(char **tab, t_map_info info)
{
	int	i;

	i = 0;
	while (i < info.x)
	{
		write(1, tab[i], info.y);
		write(1, "\n", 1);
		i++;
	}
}

char	**get_board(t_map_info info, char *map)
{
	int		i;
	int		j;
	int		row;
	char	**board;

	board = (char **) malloc((info.x + 1) * sizeof(char *));
	if (!board)
		return (NULL);
	board[0] = (char *)malloc((info.y + 1) * sizeof(char));
	if (!board[0])
		return (NULL);
	i = 0;
	row = 0;
	while (map[i] != '\n')
		i++;
	while (map[i])
	{
		if (map[i] == info.empty || map[i] == info.obstacle)
		{
			j = 0;
			while (j < info.y)
			{
				board[row][j] = map[i];
				j++;
				i++;
			}
			board[row][j] = 0;
			row++;
			board[row] = (char *) malloc((info.y + 1) * sizeof(char));
			if (!board[row])
				return (NULL);
		}
		else
			i++;
	}
	board[row] = NULL;
	print_board(board, info);
	return (board);
}
