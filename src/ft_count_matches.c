/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_count_matches.c                               .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 19:03:26 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 12:31:48 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"

int		ft_count_matches(char **tab)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		j = 0;
		count = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == '|')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int		get_first(char **tab)
{
	int j;
	int count;

	j = 0;
	count = 0;
	while (tab[0])
	{
		while (tab[0][j])
		{
			if (tab[0][j] == '|')
				count++;
			j++;
		}
	}
	return (count);
}
