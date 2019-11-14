/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 09:56:09 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 12:45:36 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_line(char *buf)
{
	int i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int		read_file(int fd, char **rest)
{
	int		ret;
	char	*buf;

	if(!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	buf[0] = 0;
	while (check_line(buf) == -1 && (ret = read(fd, buf, BUFFER_SIZE)))
	{	
		buf[ret] = '\0';
		*rest = ft_strjoin(*rest, buf);
	}
	return (ret);
}

int		get_next_line(int fd, char **line)
{
	int i;
	int ret;
	char *rest;

	i = 0;
	if (!line || read(fd, 0, 0) < 0)
		return (-1);
	rest = ft_calloc(1,1);
	ret = read_file(fd, &rest);
	*line = rest;
	return(ret);
}