/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 18:27:24 by jrandet           #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/09/08 20:25:32 by jrandet          ###   ########.fr       */
=======
/*   Updated: 2024/09/08 20:33:31 by mmouaffa         ###   ########.fr       */
>>>>>>> e9f7413cba7795d3cb6b950b2b47ea3f7346b7b8
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_isspace(char *t, int i)
{
	while (t[i] == ' ' || t[i] == ':')
		i++;
	return (i);
}

int	ft_remplissage(char *tab_dict, char **tab, int *current_pos, int pair_index)
{
	int	start_pos = *current_pos;
	int	string_len = 0;

	while (tab_dict[*current_pos] && tab_dict[*current_pos] != ' ')
		(*current_pos)++;

	tab[pair_index] = malloc(sizeof(char) * ((*current_pos) - start_pos + 1));
	if (!tab[pair_index])
		return (-1);

	while (start_pos < *current_pos)
	{
		tab[pair_index][string_len] = tab_dict[start_pos];
		start_pos++;
		string_len++;
	}
	tab[pair_index][string_len] = '\0';
	return (0);
}

int	parse_dict(char *tab_dict, char **tab_nb, char **tab_wd)
{
	int	current_pos = 0;
	int	pair_index = 0;

	while (tab_dict[current_pos])
	{
		if (ft_remplissage(tab_dict, tab_nb, &current_pos, pair_index) == -1)
		{
			write(1, "Error in memory allocation\n", 27);
			return (-1);
		}
		current_pos = ft_isspace(tab_dict, current_pos);
		if (ft_remplissage(tab_dict, tab_wd, &current_pos, pair_index) == -1)
		{
			write(1, "Error in memory allocation\n", 27);
			return (-1);
		}
		if (tab_dict[current_pos] == '\n')
			current_pos++;
		pair_index++;
	}
	return (0);
}

