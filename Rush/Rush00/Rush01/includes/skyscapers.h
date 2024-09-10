/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   skyscapers.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 13:29:53 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/01 13:38:08 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SKYSCAPERS_H
# define SKYSCAPERS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>

int compare_line(char *str, int a);
int compare_col(char *str, int a);
int input_verif(int argc, char **argv);
void	swap(int *x, int *y);
void	reverese(int arr[], int start, int end);
void	print_permutation(int arr[], int size);
void	generate_permutations(int arr[], int n);
void	skyscraper(char *arr[]);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_parse_input(char *input);
void	affichage(char indice[4][4]);

#endif