/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: hor4tio <hor4tio@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 09:56:48 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/11 10:31:34 by hor4tio     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int     main()
{
	int		fd;
	int		ret;
	int		i = 0;
	int		buffsize = 1024;
	char	buf[buffsize];
	
	fd = open("file.txt", O_RDONLY);
	ret = read(fd, buf, buffsize);
	while (buf[i] != '\n')
	{
		write(1, &buf[i], 1);
		i++;
	}
	return (0);	
	
}