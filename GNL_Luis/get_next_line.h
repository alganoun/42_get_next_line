/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: lumeyer <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/15 11:43:28 by lumeyer      #+#   ##    ##    #+#       */
/*   Updated: 2019/10/27 15:44:00 by lumeyer     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>

typedef	struct			s_stock
{
	char				*remains;
	int					fd;
	int					ret;
	char				*stmp;
	int					nl;
	struct s_stock		*next;
}						t_stock;

int						get_next_line(int fd, char **line);
char					*ft_strcat(char *dest, const char *src);
char					*strjoin_mod(char const *s1, char const *s2);
char					*strdup_mod(const char *s1);
t_stock					*ft_lstnew(int content);
void					check_n_clear(t_stock **lst, t_stock *prev);

#endif
