/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imeulema <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 15:32:53 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/11 17:28:07 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int	ft_atoi(char *str)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			nb = nb * 10 + str[i] - 48;
		else
		{
			write(1, "map error\n", 10);
			return (0);
		}
		i++;
	}
	return (nb);
}

int	get_cols(char *map, int len)
{
	int	count;

	count = 0;
	if (len >= 4)
	{
		while (map[len] != '\n')
			len++;
		len++;
	}
	if (len < 4 || map[len] == '\0')
	{
		write(1, "map error\n", 10);
		return (0);
	}
	while (map[len] != '\n')
	{
		len++;
		count++;
	}
	return (count);
}

int	verify_infos(t_map_info info)
{
	if (info.empty == info.obstacle || info.empty == info.fill
		|| info.obstacle == info.fill)
	{
		write(1, "map error\n", 10);
		return (0);
	}
	else
		return (-1);
}

t_map_info	get_first_line_info(char *map)
{
	int			i;
	int			len;
	char		*rows;
	t_map_info	info;

	len = 0;
	while (map[len] > 31)
		len++;
	info.fill = map[len - 1];
	info.obstacle = map[len - 2];
	info.empty = map[len - 3];
	i = verify_infos(info);
	rows = (char *) malloc((len - 2) * sizeof(char));
	if (!rows || i == 0)
	{
		info.x = 0;
		return (info);
	}
	while (++i + 3 < len)
		rows[i] = map[i];
	rows[i] = 0;
	info.x = ft_atoi(rows);
	free(rows);
	info.y = get_cols(map, len);
	return (info);
}
