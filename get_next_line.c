/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:35 by cmontaig          #+#    #+#             */
/*   Updated: 2024/12/04 16:50:13 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	free_strs(char **s1, char **s2, char **s3)
{
	if (s1 && *s1) {
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2) {
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3) {
		free(*s3);
		*s3 = NULL;
	}
}

char	*one_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if(!line)
		return(NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i] = buffer[i];
	return (line);
}

char	*lines_after(char *buffer)
{
	int		i;
	int		j;
	char	*line_after;

	i = 0;
	j = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line_after = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
	if(!line_after)
		return(0);
	i++;
	while (buffer[i] && buffer[i] != '\n')
	{
		line_after[j++] = buffer[i++];
	}
	if (buffer[i] && buffer[i] == '\n')
		line_after[j] = buffer[i];
	free(buffer);
	return (line_after);
}

char	*read_txt(int fd, char *txt)
{
	char	*buffer;
	char	*temp;
	int		bytes_read;

	txt = NULL;
	temp = NULL;
	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free_strs(&txt, &temp, &buffer), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(txt, buffer);
		free(txt);
		txt = temp;
		if (ft_strchr(buffer, '\n'))
			break;
	}
	free(buffer);
	return (txt);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char 		*line;

	buffer = read_txt(fd, buffer);
	if (!buffer)
	{
		// printf("erreur buffer\n");
		return (NULL);
	}
	line = one_line(buffer);
	buffer = lines_after(buffer);
	printf("line = %s\n", line); //problemes avec les printf
	printf("buffer = %s\n", buffer);
	printf("gros bozo de mes couilles = Maxence");
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;
	
	fd = open("text.txt", O_RDONLY);
	if (fd)
		printf("Ouvert avec succes\n");
	else if (fd == -1)
		// printf("Y'a un bleme la\n");
		return (0);
	line = get_next_line(fd);
	// get_next_line(fd);
	free(line);
	close(fd);
	return (0);
}

