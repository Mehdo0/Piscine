/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tableaux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:54:53 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/01 13:34:18 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scyscrapers.h"

int	input_verif(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 1)
		return (0);
	while (argv[1][i])
	{
		if (argv[1][i] > '0' || argv[1][i] > '4')
			return (0);
		i++;
	}
	if (i != 31)
		return (0);
	return (1);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write (1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	ft_putchar ((nb % 10) + '0');
}

void	ft_parse_input(char *input)
{
	int	numbers[16];
	int	index;
	int	i;

	index = 0;
	i = 0;
	if (input_verif(argc, argv) == 0)
	{
		while (*input)
		{
			if (*input >= '1' && *input <= '4')
				numbers[index++] = *input - '0';
			input++;
		}
	}
}
/*
int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		return (1);
	}

	ft_parse_input(argv[1]);
	return (0);
}
*/

// si on a besoin d'un main avec argc et argv avec un tableau a 2d
/*
#include <unistd.h>

void affichage(char indice[4][4]);

int main(int argc, char *argv[])
{
	char indice[4][4];
	int index;
	int index_y;
	int index_x;

	index = 0;
	index_x = 0;
	index_y = 0;

	if (argc != 17)
		return (1);
	
	while(index_y < 4)
	{
		index_x = 0;
		while(index_x < 4)
		{
			indice[index_y][index_x]=argv[index + 1][0];
			index++;
			index_x++;
		}
		index_y++;
	}
	affichage(indice);
	return (0);
}
*/
