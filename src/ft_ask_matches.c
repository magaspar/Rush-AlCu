/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ask_matches.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 10:46:58 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 12:16:22 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"

int			ft_ask_matches(char *player, int last)
{
	char	*str;
	int		n;

	ft_putstr(player);
	ft_putstr(" : how many matches do you want remove ? (1 - ");
	ft_putnbr(last > 3 ? 3 : last);
	ft_putstr(")\n");
	if (get_next_line(0, &str) == -1)
		return (-1);
	while (!(1 <= ft_atoi(str) && ft_atoi(str) <= (last > 3 ? 3 : last)))
	{
		free(str);
		ft_putstr("\033[31mSTOP BULLSHIT ");
		ft_putstr(player);
		ft_putstr("\n\033[0mHow many matches do you want remove ? (1 - ");
		ft_putnbr(last > 3 ? 3 : last);
		ft_putstr(")\n");
		if (get_next_line(0, &str) == -1)
			return (-1);
	}
	n = ft_atoi(str);
	free(str);
	return (n);
}
