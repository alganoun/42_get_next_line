/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/19 10:29:31 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/03 18:32:59 by lumeyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int		is_in_str(char const c, char const *set)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (i);
		i++;
	}
	return (-1);
}

int		fetch_line(t_stock *current, char **line)
{
	char	*temp;
	int		len;
	int		i;

	len = 0;
	i = -1;
	temp = current->remains;
	while (temp[len] && temp[len] != '\n')
		len++;
	if (!(*line = (char*)malloc(len + 1)))
		return (-1);
	while (++i < len && temp[i])
		(*line)[i] = temp[i];
	(*line)[i] = '\0';
	if (is_in_str('\n', temp) == -1)
	{
		if (!(current->remains = strdup_mod("")))
			return (-1);
	}
	else if (!(current->remains = strdup_mod(current->remains + i)))
		return (-1);
	free(temp);
	return (1);
}

int		read_fd(t_stock *current)
{
	char	*buf;
	char	*temp;
	size_t	ret;

	if (!(buf = (char*)malloc(BUFFER_SIZE + 1)))
		return (-1);
	buf[0] = '\0';
	ret = 0;
	while (is_in_str('\n', buf) == -1
			&& (ret = read(current->fd, buf, BUFFER_SIZE)))
	{
		buf[ret] = '\0';
		temp = current->remains;
		if (!(current->remains = strjoin_mod(current->remains, buf)))
			return (-1);
		if (temp)
			free(temp);
	}
	free(buf);
	current->ret = ret;
	return (ret);
}

t_stock	*seek_fd(t_stock **first, int fd)
{
	t_stock *current;
	t_stock *temp;

	current = *first;
	while (current)
	{
		temp = current;
		if (current->fd == fd)
			return (current);
		current = current->next;
	}
	if (!(current = ft_lstnew(fd)))
		return (NULL);
	if (*first)
		temp->next = current;
	else
		*first = current;
	if (!(current->remains = (char*)malloc(BUFFER_SIZE + 1)))
		return (NULL);
	current->remains[0] = '\0';
	return (current);
}

int		get_next_line(int fd, char **line)
{
	static t_stock	*first;
	t_stock			*current;
	t_stock			*tmp;
	int				local_ret;
	char			errbuf[1];

	if ((!line) || read(fd, errbuf, 0) < 0 || !(current = seek_fd(&first, fd)))
		return (-1);
	if (current->remains[0] == '\n')
	{
		current->stmp = current->remains;
		current->remains = strdup_mod(current->remains + 1);
		free(current->stmp);
	}
	if ((local_ret = read_fd(current)) == -1)
		return (-1);
	if (fetch_line(current, line) == -1)
		return (-1);
	if (local_ret == 0 && !(current->remains[0]))
	{
		tmp = NULL;
		check_n_clear(&first, tmp);
		return (0);
	}
	return (1);
}
