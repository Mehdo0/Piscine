/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:38:53 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/08/22 10:46:13 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str)
{
	int	compteur;

	compteur = 0;
	while (str[compteur] != '\0')
	{
		compteur ++;
	}
	return (compteur);
}
// int main() {
//     // Exemple d'utilisation de la fonction ft_strlen
//     char message[] = "Hello, World!";  
//     int length = ft_strlen(message);
//     write(1, &length, 13); 
//     return 0;
// }