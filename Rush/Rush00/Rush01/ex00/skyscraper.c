/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscraper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 11:47:50 by pitran            #+#    #+#             */
/*   Updated: 2024/09/01 13:34:16 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scyscrapers.h"

void	skyscraper(char *arr[]) /* appelle une permutaiton*/
{
	int	clue;
	int	skyscraper;
	int	i;
	int N;
	int	verification;

	clue = (arr[0][0]);
	skyscraper = 0;
	i = 0;
	N = 4; /*longueur constante de la string */
	verification = 0; /*variable de verification*/

	if (arr[] = {1, 2, 3, 4} || arr[][1] = 4)
		skyscraper = 4;

	while (i < N)
	{
		while (arr[i] < 4)
		{
			i++;
		}
		skyscraper ++; /* lorsqu'on a trouve le chiffre 4 dans la ligne, les valeurs a gauche sont des gratte-ciels visible*/
		i--
	}

	if (skyscraper != clue)
		verification = 0;
		ft_tableau /* on appelle un autre tableau pour verification */

	else 
		ft_permut /*on genere un autre ligne de permutation a verifier */
}
