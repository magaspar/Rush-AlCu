/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_remove.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 19:25:47 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 11:08:42 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"

static void	ft_remove_empty_line(char **tab, int i)
{
	int j;
	int stay;

	j = 0;
	stay = 0;
	while (tab[i - 1][j])
	{
		if (tab[i - 1][j] == '|')
			stay++;
		j++;
	}
	if (stay == 0)
	{
		if (i > 0)
			free(tab[i - 1]);
		tab[i - 1] = NULL;
	}
}

void		ft_remove(int n, char **tab)
{
	int		i;
	int		j;
	int		delete;

	i = 0;
	delete = 0;
	while (tab[i])
		i++;
	j = 0;
	while (tab[i - 1][j] && delete < n)
	{
		if (tab[i - 1][j] == '|')
		{
			tab[i - 1][j] = ' ';
			delete++;
		}
		j++;
	}
	ft_remove_empty_line(tab, i);
}
