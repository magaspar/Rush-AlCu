/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill_tab.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 17:12:43 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 16:49:25 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"
#include <stdio.h>

char			*make_line(int max, int nb)
{
	int		i;
	int		nb_space;
	char	*ret;

	i = 0;
	if (!(ret = (char*)ft_memalloc(sizeof(char) * (max + 1))))
		return (NULL);
	nb_space = (max - nb) / 2;
	while (i < nb_space)
		ret[i++] = ' ';
	while (i - nb_space < nb)
		ret[i++] = '|';
	return (ret);
}

int				ft_find_max(int *tab)
{
	int i;
	int max;

	max = 0;
	i = 0;
	while (tab[i])
	{
		if (tab[i] >= max)
			max = tab[i];
		i++;
	}
	return (max);
}

char			**fill_tab(int *nb_al)
{
	int		i;
	char	**ret;

	i = 0;
	while (nb_al[i])
		i++;
	if (!(ret = (char **)ft_memalloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (nb_al[i])
	{
		if (!(ret[i] = make_line(ft_find_max(nb_al), nb_al[i])))
			return (NULL);
		i++;
	}
	return (ret);
}

void			print_tab(char **tab)
{
	int		i;

	i = 0;
	ft_putstr("\033[1;32m");
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar('\n');
		i++;
	}
	ft_putstr("\033[0m");
}
