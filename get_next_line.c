/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 09:56:09 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/29 20:09:46 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_error(int fd, t_list **lst, char **line, char **str)
{
	if (!line || read(fd, 0, 0) < 0)
		return (-1);
	if (!(*lst))
		return (-1);
	if (!((*lst)->rest))
	{
		if (!((*lst)->rest = malloc(BUFFER_SIZE + 1)))
			return (-1);
		(*lst)->rest[0] = 0;
	}
	if (!(*str = malloc(1)))
		return (-1);
	(*str)[0] = '\0';
	return (1);
}

int		check_line(char *buf, char **rest)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
		{
			buf[i] = '\0';
			buf = buf + i + 1;
			i = 0;
			while (buf[i])
			{
				(*rest)[i] = buf[i];
				i++;
			}
			(*rest)[i] = '\0';
			return (1);
		}
		i++;
	}
	return (-1);
}

int		check_rest(char **rest1, char **rest2, char **str, char **line)
{
	if (*rest1)
	{
		if (!(*rest2 = ft_strjoin(*rest1, NULL)))
			return (-1);
		if (check_line(*rest2, rest1) != -1)
		{
			*line = *rest2;
			safe_free(str);
			return (1);
		}
	}
	return (0);
}

int		read_file(int fd, char **str, char **rest)
{
	int		ret;
	int		i;
	char	*buf;
	char	*tmp;

	i = -1;
	if (!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	buf[0] = 0;
	while (i == -1 && (ret = read(fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		i = check_line(buf, rest);
		tmp = *str;
		if (!(*str = ft_strjoin(*str, buf)))
			return (-1);
		safe_free(&tmp);
	}
	safe_free(&buf);
	if (i != -1)
		return (1);
	return (0);
}

int		get_next_line(int fd, char **line)
{
	int				ret;
	char			*str;
	t_list			*lst;
	static t_list	*begin_list;

	lst = fd_check(&begin_list, fd);
	if (check_error(fd, &lst, line, &str) == -1)
		return (-1);
	if (check_rest(&(lst->rest), &(lst->rest2), &str, line) == 1)
		return (1);
	if (check_rest(&(lst->rest), &(lst->rest2), &str, line) == -1)
		return (-1);
	ret = read_file(fd, &str, &(lst->rest));
	if (lst->rest2)
	{
		*line = ft_strjoin(lst->rest2, str);
		safe_free(&(lst->rest2));
	}
	else
		*line = str;
	safe_free(&str);
	if (ret == 0)
		lst_del(&begin_list, &lst);
	return (ret);
}
