/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:15:12 by cmontaig          #+#    #+#             */
/*   Updated: 2024/12/07 03:39:38 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"

// void	free_strs(char **s1, char **s2, char **s3)
// {
// 	if (s1 && *s1) {
// 		free(*s1);
// 		*s1 = NULL;
// 	}
// 	if (s2 && *s2) {
// 		free(*s2);
// 		*s2 = NULL;
// 	}
// 	if (s3 && *s3) {
// 		free(*s3);
// 		*s3 = NULL;
// 	}
// }

// char	*one_line(char *buffer)
// {
// 	int		i;
// 	char	*line;

// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	line = ft_calloc(sizeof(char), i + 1);
// 	if(!line)
// 		return(NULL);
// 	i = 0;
// 	while (buffer[i] && buffer[i] != '\n')
// 	{
// 		line[i] = buffer[i];
// 		i++;
// 	}
// 	if (buffer[i] && buffer[i] == '\n')
// 		line[i++] = '\n';
// 	// printf("one line return :%s\n", line);
// 	return (line);
// }

// char	*lines_after(char *buffer)
// {
// 	int		i;
// 	int		j;
// 	char	*line_after;

// 	i = 0;
// 	if (!buffer)
// 		return (NULL);
// 	while (buffer[i] && buffer[i] != '\n')
// 		i++;
// 	if (!buffer[i]) // Aucun saut de ligne
// 	{
// 		free(buffer);
// 		return (NULL);
// 	}
// 	line_after = ft_calloc(sizeof(char), ft_strlen(buffer) - i + 1);
// 	if (!line_after)
// 		return (free(buffer), NULL);
// 	i++;
// 	j = 0;
// 	while (buffer[i])
// 		line_after[j++] = buffer[i++];
// 	line_after[j] = '\0';
// 	free(buffer);
// 	return (line_after);
// }


// char *free_join(char *content, char *buffer)
// {
// 	char *new;

// 	new = ft_strjoin(content, buffer);
// 	free(content);
// 	return(new);
// }

// char	*read_txt(int fd, char *txt)
// {
// 	char	*buffer;
// 	int		bytes_read;

// 	buffer = ft_calloc(sizeof(char), (BUFFER_SIZE + 1));
// 	if (!buffer)
// 		return (NULL);
// 	bytes_read = 1;
// 	while (bytes_read != 0)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read == -1)
// 			return (free_strs(&txt, &buffer, NULL), NULL);
// 		buffer[bytes_read] = '\0';
// 		txt = free_join(txt, buffer);
// 		if (!txt)
// 			return (NULL);
// 		if (ft_strchr(buffer, '\n'))
// 			break;
// 	}
// 	free(buffer);
// 	return (txt);
// }


// char	*get_next_line(int fd)
// {
// 	static char	*buffer;
// 	char 		*line;

// 	if (BUFFER_SIZE <= 0 || fd < 0)
// 		return (NULL);
// 	buffer = read_txt(fd, buffer);
// 	if (!buffer)
// 		return (NULL);
// 	line = one_line(buffer);
// 	buffer = lines_after(buffer);
// 	return (line);
// }


// int	main(void)
// {
// 	int		fd;
// 	char	*line;
	
// 	fd = open("text.txt", O_RDONLY);
// 	if (!fd)
// 		printf("fichier pas ouvert \n");
	
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}
// 	free(line);
// 	close(fd);
// 	return (0);
// }

