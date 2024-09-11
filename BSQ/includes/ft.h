/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 11:21:57 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/11 10:49:17 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_map_info
{
	int		x;
	int		y;
	char	empty;
	char	obstacle;
	char	fill;
}	t_map_info;

typedef struct s_sqr
{
	int	size;
	int	x;
	int	y;
}	t_sqr;

void		print_board(char **tab, t_map_info info);
void		free_board(t_map_info info, char **board);
char		*get_map(char *file_name, int file);
char		**solve(char **board, t_map_info *info);
char		**get_board(t_map_info info, char *map);
char		**low_solve(char **board, t_map_info *info);
int			ft_strlen(const char *str);
int			find_max_size(t_sqr *result);
int			low_density(char **board, t_map_info *info);
int			max_density(char **board, t_map_info *info);
t_sqr		*backtrack(char **board, t_map_info *info);
t_sqr		*stock(int i, int j, int a);
t_sqr		*tri(char **board, int i, int j, t_map_info *info);
t_map_info	get_first_line_info(char *map);

#endif
