/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:13:58 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/08/22 10:25:05 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	if (b != 0)
	{
		*div = a / b;
		*mod = a % b;
	}
}

// int main(void) {
//     int a;
//     int b;
//     int div;
//     int mod;

//     a = 10;
//     b = 5;
//     ft_div_mod(a, b, &div, &mod);
//     printf("%d / %d = %d\n", a, b, div);
//     printf("%d %% %d = %d\n", a, b, mod);
//     return 0;
// }
