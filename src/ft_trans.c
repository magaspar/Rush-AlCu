/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_trans.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 21:24:03 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 11:36:56 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"

int			*ft_trans(char **tab)
{
	int i;
	int j;
	int *l;

	i = 0;
	if (!(l = (int*)ft_memalloc(sizeof(int) * 10001)))
		return (NULL);
	while (tab[i])
	{
		l[i] = 0;
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '|')
				l[i]++;
			j++;
		}
		i++;
	}
	return (l);
}

int			*ft_trans_bis(int *itab)
{
	int		i;
	int		*btab;

	if (!(btab = ft_memalloc(sizeof(int) * 10001)))
		return (NULL);
	btab[0] = (itab[0] % 4 != 1 ? 1 : 0);
	i = 1;
	while (itab[i])
	{
		btab[i] = (itab[i] % 4 != btab[i - 1] ? 1 : 0);
		i++;
	}
	return (btab);
}

int			ft_actual_line(int *itab)
{
	int i;

	i = 0;
	while (itab[i])
		i++;
	return (i - 1);
}
