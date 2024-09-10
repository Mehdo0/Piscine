/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grid.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qjacquet <qjacquet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 13:46:00 by qjacquet          #+#    #+#             */
/*   Updated: 2024/08/31 18:18:09 by qjacquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

void grid(char *up, char *right, char *down, char *left)
{
	int i;

	i = 0;
	ft_putstr(&up[i]);
	ft_putstr(&right[i]);
	ft_putstr(&down[i]);
	ft_putstr(&left[i]);
	
}

int main()
{
	char a[][] ={{"1234"},{"1234"}};
	char b[] =;
	char c[] ="1234";
	char d[] ="1234";

	grid(a, b, c, d);
}