/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alcu_two_player.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 18:58:55 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 16:22:40 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"

void		alcu_first_player(char **tab, char *player1, char *player2)
{
	int		last;
	int		n;

	last = ft_count_matches(tab);
	if (last == 0)
	{
		ft_putstr("\033[1;35m");
		ft_putstr(player1);
		ft_putstr(" wins ! \n\033[0m");
		free(tab);
		return ;
	}
	if (!(n = ft_ask_matches(player1, last)))
	{
		ft_putstr_fd("ERROR\n", 2);
		free(tab);
		return ;
	}
	ft_remove(n, tab);
	print_tab(tab);
	alcu_second_player(tab, player1, player2);
}

void		alcu_second_player(char **tab, char *player1, char *player2)
{
	int		last;
	int		n;

	last = ft_count_matches(tab);
	if (last == 0)
	{
		ft_putstr("\033[1;33m");
		ft_putstr(player2);
		ft_putstr(" wins ! \n\033[0m");
		return ;
	}
	if ((n = ft_ask_matches(player2, last)) == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return ;
	}
	ft_remove(n, tab);
	print_tab(tab);
	alcu_first_player(tab, player1, player2);
}
