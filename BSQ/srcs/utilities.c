/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:58:37 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/11 14:58:31 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	print_error(const char *msg)
{
	write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
}

int	max_density(char **board, t_map_info *info)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < info->x)
	{
		while (j < info->y)
		{
			if (board[i][j] == info->empty)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	low_density(char **board, t_map_info *info)
{
	int	i;
	int	j;

	i = 0;
	while (i < info->x)
	{
		j = 0;
		while (j < info->y)
		{
			if (board[i][j] == info->obstacle)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
