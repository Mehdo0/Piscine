/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dissection.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrandet <jrandet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 15:46:53 by alvan-de          #+#    #+#             */
/*   Updated: 2024/09/08 15:26:50 by alvan-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

// char *ft_dest()


char *ft_rterror(void)
{
	write (1, "ERROR DEST/n", 11);
		return(NULL);
}

char *ft_undeux(int c, int i, int j, char *str)
{
	char *dest;
	dest = malloc ((ft_strlen(str) % 3) + 1);
		while (++c < (ft_strlen(str) % 3))
			dest[c] = str[c];
	return (dest);	
}


char	**ft_dissection(char *str)
{
	int i;
	int j;
	int c;
	char *dest;
	char **tab;

	c = -1;
	j = 0;
	i = 0;
	tab = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!tab)
		ft_rterror();
	if ((ft_strlen(str) % 3) > 0)
	{
		tab[i] = ft_undeux(c, i, j, str);
		j = (ft_strlen(str) % 3);
	}
	while (j < ft_strlen(str))
	{
		i++;
		c = -1;
		dest = malloc(4);
		if (!dest)
			ft_rterror();
		while (++c < 3)
		{
			dest[c] = str[j];
			j++;
		}		
		dest[3] = '\0';
		tab[i] = dest;	
	}
	return (tab);
}
