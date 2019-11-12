/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 09:56:09 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 20:32:06 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		line_checker(char *str)
{
	int i;
	int EOL;

	i = 0;
	EOL = 0;
	while (str[i] != '\n')
	{
		if (str[i] == '\n')
			EOL++;
		i++;
	}
	return (EOL);
}
											//il y a trois cas de figure a gerer : BUFF_SIZE trop grand, trop petit et de la bonne taille

char 	*line_in_rest(char *rest)
{
	int		i;
	char	*newline;

	i = 0;
	while(rest[i])
	{
		if ( rest[i] == '\n')
		{
			newline = ft_calloc(i + 1, 1);
			ft_strlcpy(newline, rest, i + 1);
			return (newline);
		}
		i++;
	}
	return (rest);
}

int		get_next_line(int fd, char **line)
{
	int 		ret;
	int			i;
	int			j;
	char 		buf[BUFFER_SIZE];
	static char *rest;
	
	i = 0;
	j = 0;
	ret = read(fd, buf, BUFFER_SIZE);
	if (line_checker(rest) > 0)
	{	
		*line = line_in_rest(rest);
		return(1);
	}
	else if (line_checker(buf) > 0)
	{
		while(buf[i] != '\n')
		{
			*line[i] = buf[i];
			i++;
		}
		if (i < BUFFER_SIZE && buf[i] != 0)
		{
			rest = ft_calloc(BUFFER_SIZE - i + 1, 1);
			while(i < BUFFER_SIZE)
				rest[j++] = buf[i++];
		}
		return (1);
	}
	return (0);
}