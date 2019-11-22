/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line_utils.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/24 14:52:31 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/25 10:35:38 by lumeyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcat(char *dest, const char *src)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*strjoin_mod(char const *s1, char const *s2)
{
	size_t	len;
	char	*dest;
	int		len1;
	int		len2;

	len1 = 0;
	len2 = 0;
	if (s1 == NULL)
		return (strdup_mod(s2));
	if (!s2)
		return (NULL);
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	len = len1 + len2 + 1;
	if (!(dest = (char*)malloc(len * sizeof(char))))
		return (NULL);
	*dest = 0;
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}

char	*strdup_mod(const char *s1)
{
	char	*copy;
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	if (!(copy = (char*)malloc(len + 1)))
		return (NULL);
	while (s1[i])
	{
		copy[i] = s1[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

t_stock	*ft_lstnew(int content)
{
	t_stock	*new;

	if (!(new = malloc(sizeof(t_stock))))
		return (NULL);
	new->fd = content;
	new->next = NULL;
	return (new);
}

void	check_n_clear(t_stock **lst, t_stock *prev)
{
	t_stock *current;

	current = *lst;
	while (current)
	{
		if (!current->ret && !current->remains[0] && (*lst)->next == NULL)
		{
			free(current->remains);
			free(*lst);
			*lst = NULL;
			break ;
		}
		else if (!current->ret && current->remains[0] && current != *lst)
		{
			prev->next = current->next;
			free(current->remains);
			free(current);
			current = prev->next;
		}
		else
		{
			prev = current;
			current = current->next;
		}
	}
}
