/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hor4tio <hor4tio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:43:47 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 15:57:01 by hor4tio     ###    #+. /#+    ###.fr     */
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