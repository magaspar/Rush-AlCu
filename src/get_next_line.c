/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 12:25:45 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 16:23:17 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/alum1.h"

t_save			*search_fd(int fd, t_save **save)
{
	if (!*save)
	{
		*save = (t_save*)malloc(sizeof(t_save));
		if (*save == NULL)
			return (NULL);
		(*save)->fd = fd;
		(*save)->buf = NULL;
		(*save)->next = NULL;
	}
	if ((*save)->fd == fd)
		return (*save);
	return (search_fd(fd, &((*save)->next)));
}

int				get_line(char *s)
{
	int		i;

	if (!s)
		return (-1);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i])
		return (i);
	else
		return (-1);
}

void			del_save(t_save **alst)
{
	t_save		*tmp;

	tmp = (*alst)->next;
	ft_strdel(&(*alst)->buf);
	free(*alst);
	*alst = tmp;
}

void			ft_norm(char **line, t_save *tmp)
{
	int			r;

	r = get_line(tmp->buf);
	if (r != -1)
	{
		*line = ft_strsub(tmp->buf, 0, r);
		tmp->buf = ft_strsubf(tmp->buf, r + 1,
				ft_strlen(tmp->buf) - (r + 1));
	}
	else
	{
		*line = ft_strdup(tmp->buf);
		ft_strdel(&tmp->buf);
	}
}

int				get_next_line(const int fd, char **line)
{
	int					ret;
	char				buf[BUFF_SIZE + 1];
	t_save				*tmp;
	static t_save		*save = NULL;

	if (!line || fd < 0)
		return (-1);
	tmp = search_fd(fd, &save);
	ret = 1;
	while (ret && get_line(tmp->buf) == -1)
	{
		ret = read(fd, buf, BUFF_SIZE);
		if (ret == -1)
			return (-1);
		buf[ret] = '\0';
		tmp->buf = ft_strjoinf(tmp->buf, buf);
	}
	ft_norm(line, tmp);
	if (!ret && !**line && !tmp->buf)
	{
		del_save(&tmp);
		return (0);
	}
	return (1);
}
