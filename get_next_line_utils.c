/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: alganoun <alganoun@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/11/11 12:05:26 by hor4tio      #+#   ##    ##    #+#       */
/*   Updated: 2019/11/14 12:31:14 by alganoun    ###    #+. /#+    ###.fr     */
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
char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		maxlen;
	char	*dst;

	i = 0;
	j = 0;
	if (s1 == NULL)
		return (NULL);
	maxlen = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	if (!(dst = (char *)malloc((maxlen + 1) * sizeof(char))))
		return (NULL);
	while (j < (int)ft_strlen(s1))
		dst[i++] = s1[j++];
	j = 0;
	while (j < (int)ft_strlen(s2))
		dst[i++] = s2[j++];
	dst[i] = '\0';
	return (dst);
}