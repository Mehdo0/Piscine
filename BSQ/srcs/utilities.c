/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:58:37 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/10 12:27:07 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

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
