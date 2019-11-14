/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:43:47 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 12:33:41 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line);

int		main()
{
	int fd;
	int ret;
	char *line;

	fd = open("file.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%d\n", ret);
	printf("%s", line);
	return (0);
}