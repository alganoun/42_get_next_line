/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:05:26 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/12 20:29:28 by alganoun    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*t;

	i = 0;
	t = s;
	while (i < n)
	{
		t[i] = 0;
		i++;
	}
}

int		ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

void		*ft_calloc(size_t count, size_t size)
{
	void	*tab;
	size_t	len;

	len = count * size;
	if (!(tab = malloc(len)))
		return (NULL);
	ft_bzero(tab, len);
	return (tab);
}

size_t		ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	if (dst == NULL || src == NULL)
		return (0);
	else if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (ft_strlen(src));
}
