/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dictionary.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 00:14:08 by jrandet           #+#    #+#             */
/*   Updated: 2024/09/08 20:33:30 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

char *read_dictionary(char *filename)
{
	int		fd;
	int		c_count;
	char	*tab_dict;

	fd = open_file(filename);
	if (fd == -1)
		return (NULL);
	c_count = count_characters(fd);
	close(fd);
	tab_dict = read_inside_file(filename, c_count);
	if (!tab_dict)
		return (NULL);
	return (tab_dict);
}