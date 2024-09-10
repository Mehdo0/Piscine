/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/23 10:17:40 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/08/23 10:22:02 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	maj(char c)
{
	if (64 < c && c < 91)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	min(char c)
{
	if (96 < c && c < 123)
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

int	ft_str_is_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (maj(str[i]) == 0 && min(str[i]) == 0)
		{
			return (0);
		}
		else
		{
			i++;
		}
	}
	return (1);
}
