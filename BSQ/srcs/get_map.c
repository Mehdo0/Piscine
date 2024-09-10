/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:03 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/10 13:09:26 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

#include <stdio.h>

int	get_total_size(char *file_name)
{
	int		file_desc;
	int		total_size;
	char	temp[1];

	file_desc = open(file_name, O_RDONLY);
	if (!file_desc)
		return (-1);
	total_size = 0;
	while (read(file_desc, temp, 1))
			total_size++;
	close(file_desc);
	return (total_size);
}

char	*read_from_file(char *file_name)
{
	char	*content;
	char	temp[1];
	int		i;
	int		file_desc;

	content = (char *) malloc(((get_total_size(file_name)) + 1) * sizeof(char));
	file_desc = open(file_name, O_RDONLY);
	if (!content || !file_desc)
		return (NULL);
	i = 0;
	while (read(file_desc, temp, 1))
	{
		content[i] = temp[0];
		i++;
	}
	content[i] = 0;
	close(file_desc);
	return (content);
}

char	*get_map(char *file_name)
{
	char	*content;

	content = read_from_file(file_name);
	if (!content)
	{
		write(1, "Error opening file\n", 19);
		return (NULL);
	}
	return (content);
}
