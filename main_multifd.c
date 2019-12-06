/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main_multifd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:43:47 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/12/04 16:32:17 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		main()
{
	int		ret;
	int		fd;
	int		fd2;
	int		fd3;
	char	*line;

	ret = 1;
	fd = open("Files/file.txt", O_RDONLY);
	fd2 = open("Files/empty.txt", O_RDONLY);
	fd3 = open("Files/bible.txt", O_RDONLY);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd3, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd2, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd3, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	ret = get_next_line(fd3, &line);
	printf("%s\n", line);
	printf("ret = %d\n", ret);
	free(line);
	while (ret > 0)
	{
		ret = get_next_line(fd3, &line);
		free(line);
	}
	printf("ret = %d\n", ret);
	return (0);
}
