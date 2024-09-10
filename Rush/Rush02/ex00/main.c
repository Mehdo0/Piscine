/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 14:16:29 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/08 20:44:59 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	test(int ac, char **av)
{
	int	i;
	int	j;

	j = 0;
	if (ac > 3 || ac < 2)
		return (0);
	while (av[j])
	{
		i = 0;
		while (av[j][i])
		{
			if (i == '-')
				return (0);
			i++;
		}
		j++;
	}
	return (1);
}

int	main(int argc, char **argv)
{	
	char	*tab_dict;
	char	**tab_nb;
	char	**tab_wd;
	int		lines;
	char	**tab;

	if (test(argc, argv) == 0)
	{
		write(2, "Error!\n", 22);
		return (0);
	}
	tab_dict = read_dictionary(argv[1]);
	if (!tab_dict)
		return (-1);
	lines = nb_de_lignes(tab_dict);
	tab_nb = malloc(sizeof(char *) * lines);
	tab_wd = malloc(sizeof(char *) * lines);
	if (!tab_nb || !tab_wd)
	{
		ft_free(tab_dict, tab_nb, tab_wd, lines);
		write(2, "Error!\n", 7);
		return (-1);
	}
	if (parse_dict(tab_dict, tab_nb, tab_wd) == -1)
		write(1, "Error\n", 7);
	ft_free(tab_dict, tab_nb, tab_wd, lines);
	tab = ft_dissection(argv[1]);
	linke(tab_nb, tab_wd, tab);
	return (0);

}
