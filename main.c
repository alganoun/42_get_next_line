/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:43:47 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/25 19:33:34 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int		fd;
	int 	fd2;
	int		fd3;
	char	*line;
	
	fd = open("Files/file.txt", O_RDONLY);
	fd2 = open("Files/empty.txt", O_RDONLY);
	fd3 = open("Files/bible.txt", O_RDONLY);
	while (get_next_line(fd, &line))
	{
		printf("%s\n", line);
		free(line);
	}
	free(line);
	return (0);
}
