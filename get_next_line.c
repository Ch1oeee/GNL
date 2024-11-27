/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:24:35 by cmontaig          #+#    #+#             */
/*   Updated: 2024/11/27 16:51:23 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


void	read_txt(int fd)
{
		
}


char	*get_next_line(int fd)
{
	char	*buffer;
	int		bytesRead;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	bytesRead = read (fd, buffer, sizeof(buffer));
	
	// printf("%d bytes read!\n", bytesRead);
	// printf("File Contents: %s\n", buffer);
	
	return (0);
	
}
int	main(void)
{
	int	fd;
	fd = open("text.txt", O_RDONLY);

	return (0);
}