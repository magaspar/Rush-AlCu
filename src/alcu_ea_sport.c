/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alcu_ea_sport.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 16:11:46 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 16:22:27 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/libft.h"
#include "../header/alum1.h"

int		alcu_versus_ia(char **tab)
{
	int		n;

	n = ft_ask_yes_no("\033[1;36mDo you want starting ?\033[0m");
	if (n == 1)
		alcu_player(tab);
	else if (n == 0)
		alcu_ia(tab);
	else if (n == -1)
		ft_putstr_fd("ERROR\n", 2);
	return (0);
}

char	*ft_norme(char *player, char *name, char *color)
{
	char	*tmp;

	ft_putstr("Put the name of ");
	ft_putstr(name);
	ft_putstr(" :\n");
	if (get_next_line(0, &player) == -1)
		return (NULL);
	tmp = player;
	if (!(player = ft_strjoin(color, player)))
		return (NULL);
	free(tmp);
	return (player);
}

void	alcu_config_dual(char **tab)
{
	char	*player1;
	char	*player2;

	if (!(player1 = ft_norme(player1, "Player 1", "\033[1;35m")))
	{
		ft_putstr_fd("ERROR\n", 2);
		return ;
	}
	if (!(player2 = ft_norme(player2, "Player2", "\033[1;33m")))
	{
		ft_putstr_fd("ERROR\n", 2);
		return ;
	}
	alcu_first_player(tab, player1, player2);
}

void	alcu_ea_sport(char **tab)
{
	int		n;

	ft_putstr("\033[1;36mYou will play with the following board :\n");
	print_tab(tab);
	n = ft_ask_yes_no("\033[1;36mDo you want play alone ?\033[0m");
	if (n == 1)
		alcu_versus_ia(tab);
	else if (n == 0)
		alcu_config_dual(tab);
	else if (n == -1)
		ft_putstr_fd("ERROR\n", 2);
}
