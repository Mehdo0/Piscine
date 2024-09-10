/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:10:23 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/08/22 10:12:31 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

// int main(void) {
//     int x = 42;
//     int y = 24;

//     printf ("Avant échange : x = %d, y = %d\n", x, y);
//     ft_swap (&x, &y);
//     printf ("Après échange : x = %d, y = %d\n", x, y);
//     return (0);
// }
