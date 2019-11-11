/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hor4tio <hor4tio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 09:56:09 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 15:59:54 by hor4tio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str);

int 	get_next_line(int fd, char **line)
{
	int 		ret;
	int			i;
	char 		buf[1024];
	static char *rest;
	
	i = 0;
	ret = read(fd, buf, 1024);
	while (buf[i] != '\n')
		i++;
	if(!(rest = malloc(i + 1)))
		return (-1);
	i = 0;
	while (buf[i] != '\n')
	{
		rest[i] = buf[i];
		i++;
	}
	rest[i] = '\0';
	*line = rest;
	if (fd > 0 && ft_strlen(rest) > 0)
		return (1);
	return (0);
}