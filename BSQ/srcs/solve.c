/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 13:34:54 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/11 14:42:35 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

t_sqr	*update_result(t_sqr *resultat, t_sqr *current_result)
{
	if (!resultat || (current_result && current_result->size > resultat->size))
	{
		free(resultat);
		return (current_result);
	}
	free(current_result);
	return (resultat);
}

t_sqr	*backtrack(char **board, t_map_info *info)
{
	int		i;
	int		j;
	t_sqr	*resultat;
	t_sqr	*current_result;

	i = 0;
	resultat = NULL;
	if (max_density(board, info) || low_density(board, info))
		return (NULL);
	while (i < info->x)
	{
		j = 0;
		while (j < info->y)
		{
			if (board[i][j] == info->empty)
			{
				current_result = tri(board, i, j, info);
				resultat = update_result(resultat, current_result);
			}
			j++;
		}
		i++;
	}
	return (resultat);
}

t_sqr	*stock(int i, int j, int a)
{
	t_sqr	*result;

	result = (t_sqr *)malloc(sizeof(t_sqr));
	if (!result)
		return (NULL);
	result->size = a;
	result->x = i;
	result->y = j;
	return (result);
}

t_sqr	*tri(char **board, int i, int j, t_map_info *info)
{
	int	a;
	int	x;
	int	y;

	a = 0;
	while (i + a < info->x && j + a < info->y)
	{
		x = 0;
		while (x <= a)
		{
			y = 0;
			while (y <= a)
			{
				if (board[i + x][j + y] == info->obstacle)
					return (stock(i, j, a));
				y++;
			}
			x++;
		}
		a++;
	}
	return (stock(i, j, a));
}

char	**solve(char **board, t_map_info *info)
{
	t_sqr	*result;
	int		i;
	int		j;

	result = backtrack(board, info);
	if (!result)
	{
		free(result);
		return (low_solve(board, info));
	}
	i = result->x;
	while (i < result->x + result->size)
	{
		j = result->y;
		while (j < result->y + result->size)
		{
			board[i][j] = info->fill;
			j++;
		}
		i++;
	}
	free(result);
	return (board);
}
