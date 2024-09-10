/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   jsp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouaffa <mmouaffa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 20:56:04 by mmouaffa          #+#    #+#             */
/*   Updated: 2024/09/08 21:14:45 by mmouaffa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

FILE	*read_file(const char *filename)
{
	FILE	*file;

	*file = fopen(filename, "r");
	if (!file)
	{
		write(1, "Error!\n", 7);
	}
	return (file);
}

int	extract_data(char *line, char **number, char **literal)
{
	*number = my_strtok(line, " :\n");
	*literal = my_strtok(NULL, " :\n");
	return (*number && *literal);
}

int	resize_arrays(char ***numbers, char ***literals, int *capacity)
{
	*capacity *= 2;
	*numbers = realloc(*numbers, *capacity * sizeof(char *));
	*literals = realloc(*literals, *capacity * sizeof(char *));
	if (!(*numbers) || !(*literals))
	{
		write(1, "Error!\n", 7);
		return (-1);
	}
	return (0);
}

void	free_memory(char **numbers, char **literals, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(numbers[i]);
		free(literals[i]);
		i++;
	}
	free(numbers);
	free(literals);
}

int	parse_file(const char *filename, char ***num, char ***l, int *size)
{
	char 	*num;
	char 	*literal;
	char	line[256];
	int		capacity;
	int		count;
	FILE 	*file;

    capacity = 10;
	count = 0;
	*file = read_file(filename);
	if (!file)
		return (-1);
	*num = malloc(capacity * sizeof(char *));
	*l = malloc(capacity * sizeof(char *));
	if (!(*num) || !(*l))
	{
		perror("Erreur d'allocation mémoire");
		fclose(file);
		return (-1);
	}

	while (fgets(line, sizeof(line), file))
	{
		if (count >= capacity && resize_arrays(num, l, &capacity) == -1)
		{
			fclose(file);
			return (-1);
		}

		*num = NULL;
		*literal = NULL;
		if (extract_data(line, &num, &literal))
		{
			(*num)[count] = strdup(num);
			(*l)[count] = strdup(literal);
			count++;
		}
	}
	fclose(file);
	*size = count;
	return (0);
}
