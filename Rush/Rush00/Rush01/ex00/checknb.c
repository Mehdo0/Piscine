/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checknb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 16:13:37 by qjacquet          #+#    #+#             */
/*   Updated: 2024/09/01 13:34:14 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scyscrapers.h"

int	compare_line(char *str, int a)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == a + '0')
			n++;
		i++;
	}
	if (n > 1)
		return (0);
	return (1);
}

int	compare_col(char *str, int a)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == a + '0')
			n++;
		i++;
	}
	if (n > 1)
		return (0);
	return (1);
}
/*
#include <stdio.h>
int main()
{
	char a[] = "1234";
	printf("%d", compare(a, 2));
}
*/
