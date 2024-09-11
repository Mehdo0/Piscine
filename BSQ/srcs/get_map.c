/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:20:03 by imeulema          #+#    #+#             */
/*   Updated: 2024/09/11 14:54:03 by imeulema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

unsigned long long	get_total_size(char *file_name, int file)
{
	int						file_desc;
	unsigned long long		total_size;
	char					temp[1];

	file_desc = 0;
	if (file == 1)
		file_desc = open(file_name, O_RDONLY);
	else if (file == 0)
		file_desc = 0;
	else
		file_desc = 42;
	if (!file_desc)
		return (-1);
	total_size = 0;
	while (read(file_desc, temp, 1))
			total_size++;
	if (file_desc != 0)
		close(file_desc);
	return (total_size);
}

char	*read_from_file(char *file_name, int file)
{
	char	*content;
	char	temp[1];
	int		i;
	int		file_desc;

	content = (char *) malloc(((get_total_size(file_name, file)) + 1)
			* sizeof(char));
	if (file == 1)
		file_desc = open(file_name, O_RDONLY);
	else if (file == 0)
		file_desc = 0;
	if (!content)
		return (NULL);
	i = 0;
	while (read(file_desc, temp, 1))
	{
		content[i] = temp[0];
		i++;
	}
	content[i] = 0;
	if (file_desc != 0)
		close(file_desc);
	return (content);
}

char	*get_map(char *file_name, int file)
{
	char	*content;

	content = read_from_file(file_name, file);
	if (!content)
	{
		write(1, "Error opening file\n", 19);
		return (NULL);
	}
	return (content);
}
