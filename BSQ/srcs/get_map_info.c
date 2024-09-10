/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:32:53 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/09 18:28:03 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

// peut=etre ajouter une securite au cas ou on aurait autre chose que des
// chiffres dans rows
int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb);
}

int	get_cols(char *map, t_map_info info, int len)
{
	int	count;

	count = 0;
	while (map[len] != info.empty && map[len] != info.obstacle)
		len++;
	while (map[len] == info.empty || map[len] == info.obstacle)
	{
		len++;
		count++;
	}
	return (count);
}

// besoin d'allouer de la memoire pour une struct ?
t_map_info	get_first_line_info(char *map)
{
	int			i;
	int			len;
	char		*rows;
	t_map_info	info;

	i = 0;
	len = 0;
	while (map[len] > 31)
		len++;
	info.fill = map[len - 1];
	info.obstacle = map[len - 2];
	info.empty = map[len - 3];
	rows = (char *) malloc((len + 1) * sizeof(char));
	if (!rows)
	{
		info.x = 0;
		return (info);
	}
	while (i + 3 < len)
	{
		rows[i] = map[i];
		i++;
	}
	rows[i] = 0;
	info.x = ft_atoi(rows);
	free(rows);
	info.y = get_cols(map, info, len);
	return (info);
}
