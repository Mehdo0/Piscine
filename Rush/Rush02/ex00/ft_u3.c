/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:06:18 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/08 21:07:46 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_recursive_power(int nb, int power)
{
	int	result;

	result = nb;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		return (nb * ft_recursive_power(nb, power - 1));
	}
	return (nb);
}

char	*skip_initial_delimiters(char *str, const char *delim)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (delim[i] != '\0')
		{
			if (*str == delim[i])
			{
				str++;
				break ;
			}
			i++;
		}
		if (delim[i] == '\0')
			break ;
	}
	return (str);
}

char	*find_token_end(char *str, const char *delim)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (delim[i] != '\0')
		{
			if (*str == delim[i])
			{
				*str = '\0';
				return (str + 1);
			}
			i++;
		}
		str++;
	}
	return (NULL);
}

char	*my_strtok(char *str, const char *delim)
{
	static char	*next_token;
	char		*token_start;

	next_token = NULL;
	if (str != NULL)
		next_token = str;
	else if (next_token == NULL)
		return (NULL);
	next_token = skip_initial_delimiters(next_token, delim);
	if (*next_token == '\0')
	{
		next_token = NULL;
		return (NULL);
	}
	*token_start = next_token;
	next_token = find_token_end(next_token, delim);
	return (token_start);
}
