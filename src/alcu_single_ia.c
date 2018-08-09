/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alcu_single_ia.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 20:19:48 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:14:50 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"

void			alcu_player(char **tab)
{
	int			last;
	char		*str;
	int			n;

	last = ft_count_matches(tab);
	if (last == 0)
	{
		ft_putstr("\033[1;33mPlayer  wins !\n");
		free(tab);
		return ;
	}
	if ((n = ft_ask_matches("\033[1;33mPlayer", last)) == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return ;
	}
	ft_remove(n, tab);
	print_tab(tab);
	alcu_ia(tab);
}

static void		alcu_ia_end(char **tab, int *itab, int *btab)
{
	int		i;
	int		n;

	i = ft_actual_line(itab);
	n = (itab[i] % 4) - (i - 1 >= 0 ? btab[i - 1] : 1);
	n = (n == 0 ? 1 : n);
	n = (n == -1 ? 3 : n);
	ft_putstr("\033[1;35mIA tooks ");
	ft_putnbr(n);
	ft_putstr(" matches.\033[0m\n");
	ft_remove(n, tab);
	print_tab(tab);
	free(itab);
	free(btab);
	alcu_player(tab);
}

void			alcu_ia(char **tab)
{
	int		*itab;
	int		*btab;

	if (!ft_count_matches(tab))
	{
		ft_putstr("\033[1;31mYOU LOOSE !\nBECAUSE I WIN\n");
		ft_putstr("BECAUSE I AM BATMAN\n");
		ft_putbatman();
		free(tab);
		return ;
	}
	if (!(itab = ft_trans(tab)))
	{
		ft_putstr_fd("ERROR\n", 2);
		return ;
	}
	if (!(btab = ft_trans_bis(itab)))
	{
		ft_putstr_fd("ERROR\n", 2);
		return ;
	}
	alcu_ia_end(tab, itab, btab);
}
