/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_step.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 15:09:28 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/08 20:45:37 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	cherche(char **tab_chiffre, char **tab, int nbr, int j)
{
	int	i;

	i = 0;
	while (tab_chiffre[i])
	{
		if (tab_chiffre[i][0] == tab[nbr][j])
			return (i);
		i++;
	}
	return (-1);
}

void	condition_10(char **tab, int i, int j)
{
	if (j == 0)
		write(1, "hundred", 7);
	if (j == 1)
		tab[i][j] = (tab[i][j] - '0') * 10 + '0';
}

int	condition_100(char **tab, int i)
{
	int	j;
	int	result;
	int	k;

	result = 1;
	k = 1;
	j = 0;
	while (tab[i][j])
		j++;
	while (k < j)
	{
		result *= 10;
		k++;
	}

	return (result);
}

int	condition_20(char **tab, int i, char **l)
{
	int	nbr;

	nbr = 10;
	if (tab[i][1] == '1')
	{
		nbr += tab[i][2];
		write(1, l[nbr] ' ', (ft_strlen(l[nbr]) + 1));
	}
	return (i++);
}

char	*linke(char **c, char **l, char **tab)
{
	int	i;
	int	j;
	int	chercheur;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			condition_20(tab, i, l);
			chercheur = cherche(c, tab, i, j);
			if (chercheur != -1)
				write(1, l[chercheur] ' ', (ft_strlen(l[chercheur] + 1)));
			condition_10(tab, i, j);
			j++;
		}
		chercheur = cherche(c, condition_100(tab, i));
		if (chercheur != -1)
			write(1, l[chercheur] ' ', (ft_strlen(l[chercheur]) + 1));
		i++;
	}
	return (NULL);
}