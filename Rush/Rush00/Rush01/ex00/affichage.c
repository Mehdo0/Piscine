/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:46:00 by qjacquet          #+#    #+#             */
/*   Updated: 2024/09/01 13:34:13 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scyscrapers.h"

void	affichage(char indice[4][4])
{
	int	index_y;
	int	index_x;

	index_x = 0;
	index_y = 0;
	while (index_y < 4)
	{
		index_x = 0;
		while (index_x < 4)
		{
			write(1, &indice[index_y][index_x], 1);
			index_x++;
		}
		write (1, "\n", 1);
		index_y++;
	}
}
/*
int main()
{
	char a[4][4] = {{'1','2','3','4'}, {'1','2','3','4'}, {'1','2','3','4'}, {'1','2','3','4'}};
	affichage(a);
}*/

// si on utilise plusieurs tableau pour afficher le tableau
/*#include <unistd.h>

void ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i++], 1);
		if (i % 4 == 0)
		write (1, "\n", 1);
	}
}

void grid(char *line1, char *line2, char *line3, char *line3)
{
	int i;

	i = 0;
	ft_putstr(&up[i]);
	ft_putstr(&right[i]);
	ft_putstr(&down[i]);
	ft_putstr(&left[i]);
	
}
*/
