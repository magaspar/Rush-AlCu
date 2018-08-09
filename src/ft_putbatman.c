/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putbatman.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/17 19:07:29 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:58:29 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"
#include "../header/libft.h"

static void	ft_sleep(int time)
{
	size_t i;

	i = 0;
	while (i < time * 508200)
		i++;
}

void		ft_putbatman(void)
{
	int		fd;
	int		i;
	char	*str;

	ft_sleep(3000);
	i = 0;
	while (i < 83)
	{
		ft_putchar('\n');
		i++;
	}
	ft_sleep(1000);
	fd = open("src/batman", O_RDONLY);
	while (get_next_line(fd, &str))
	{
		ft_sleep(100);
		ft_putstr(str);
		ft_putchar('\n');
		free(str);
	}
}
