/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                             :+:      :+:    :+: */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 13:12:34 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/08/24 15:56:42 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	rush(int x, int y)
{
	int	l;
	int	c;

	l = 0;
	if (x <= 0 || y <= 0)
		return ;
	while (l < y)
	{
		c = 0;
		while (c < x)
		{
			if ((l == 0 || l == y - 1) && (c == 0 || c == x - 1))
				ft_putchar('o');
			else if (l == 0 || l == y - 1)
				ft_putchar('-');
			else if (c == 0 || c == x - 1)
				ft_putchar('|');
			else
				ft_putchar(' ');
			c++;
		}
		ft_putchar('\n');
		l++;
	}
}
