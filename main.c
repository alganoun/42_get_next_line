/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:43:47 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 19:52:07 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int		ret;
	int		fd;
	char	*line;

	ret = 1;
	fd = open("Files/file.txt", O_RDONLY);
	while (ret > 0)
	{
		ret = get_next_line(fd, &line);
		printf("%s\n", line);
		printf("%d\n", ret);
		free(line);
	}
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("%d", ret);
	return (0);
}
