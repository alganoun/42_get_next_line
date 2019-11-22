/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_bonus.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 09:56:09 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/22 18:38:40 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		check_error(int fd, t_list **lst, char **line, char **str)
{
	if (!line || read(fd, 0, 0) < 0)
		return (-1);
	if (!(*lst))
		return (-1);
	if(!((*lst)->rest))
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

t_list	*fd_check(t_list **list, int fd)
{
	t_list	*tmp;
	
	if(!(*list))
		return (*list = lstnew(fd));
	tmp = *list;
	while(tmp && tmp->fd != fd)
	{
		if(tmp->next == NULL)
		{
			lstadd_back(&tmp, fd);
			return(tmp->next);
		}
		tmp = tmp->next;
	}
	return(tmp);
}

int		check_line(char *buf, char **rest)
{
	int 	i;
	
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

int		read_file(int fd, char **str, char **rest)
{
	int		ret;
	int		i;
	char	*buf;

	i = -1;
	if(!(buf = malloc(BUFFER_SIZE + 1)))
		return (-1);
	buf[0] = 0;
	while ( i == -1 && (ret = read(fd, buf, BUFFER_SIZE)))
	{	
		buf[ret] = '\0';
		i = check_line(buf, rest);
		*str = ft_strjoin(*str, buf);
	}
	if (i != -1)
		return(1);
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
	if (lst->rest)
	{	
		lst->rest2 = ft_strjoin(lst->rest, NULL);
		if (check_line(lst->rest2, &(lst->rest)) != -1)
		{
			*line = lst->rest2;
			return (1);
		}
	}
	ret = read_file(fd, &str, &(lst->rest));
	if (lst->rest2)
		*line = ft_strjoin(lst->rest2, str);
	else
		*line = str;
	if (ret == 0 && lst->rest && check_line(lst->rest2, &(lst->rest)) == -1)
		lst_del(&begin_list, &lst);
	return(ret);
}
