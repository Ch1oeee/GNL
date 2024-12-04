/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmontaig <cmontaig@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:15:12 by cmontaig          #+#    #+#             */
/*   Updated: 2024/12/04 16:22:18 by cmontaig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	return (line_after);
}

int	main(void)
{
	char *buffer = "yeaa\naaah\n sdhdshj sdsd";
	printf("%s\n", lines_after(buffer));
	return (0);
}
