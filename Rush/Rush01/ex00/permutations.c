/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 15:12:58 by pitran            #+#    #+#             */
/*   Updated: 2024/09/01 13:36:21 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scyscrapers.h"

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	reverese(int arr[], int start, int end)
{
	while (start < end)
	{
		swap(&arr[start], &arr[end]);
		start++;
		end--;
	}
}

// void	print_permutation(int arr[], int size)
// {
// 	char	c;
// 	int		i;

// 	i = 0;
// 	while (i < size)
// 	{
// 		c = arr[i] + '0';
// 		write(1, &c, 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// }

void	generate_permutations(int arr[], int n)
{
	int	i;
	int	j;
	int	has_next;

	i = 1;
	j = 1;
	has_next = 1;
	while (has_next)
	{

		i = n - 2;
		while (i >= 0 && arr[i] >= arr[i + 1])
			i--;
		if (i < 0)
			has_next = 0;
		else
		{
			j = n - 1;
			while (arr[j] <= arr[i])
				j--;
			swap(&arr[i], &arr[j]);
			reverse(arr, i + 1, n - 1);
		}
	}
}

// int	main(void)
// {
// 	int	arr[4];
// 	int	n;

// 	n = 4;
// 	arr[4] = {1, 2, 3, 4};
// 	generate_permutations(arr, n);
// 	return (0);
// }
