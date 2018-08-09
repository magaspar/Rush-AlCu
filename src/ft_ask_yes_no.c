/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ask_yes_no.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 11:10:55 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 11:27:41 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"

int			ft_ask_yes_no(char *question)
{
	char	*str;

	ft_putstr(question);
	ft_putstr(" (yes/no)\n");
	if (get_next_line(0, &str) == -1)
		return (-1);
	while (ft_strcmp(str, "yes") && ft_strcmp(str, "no"))
	{
		free(str);
		ft_putstr("\033[31mSTOP BULLSHIT\033[0m\n");
		ft_putstr("Just say yes or no\n");
		ft_putstr(question);
		ft_putchar('\n');
		if (get_next_line(0, &str) == -1)
			return (-1);
	}
	if (ft_strcmp(str, "yes") == 0)
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}
