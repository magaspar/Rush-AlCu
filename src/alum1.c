/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alum1.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 14:04:56 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:14:12 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../header/alum1.h"

int				*ft_recup_from_input(int *nb_al)
{
	char	*str;
	int		i;

	ft_putstr("Please, configure the board :\n");
	str = ft_strdup("bijour");
	i = 0;
	while (ft_strcmp(str, ""))
	{
		free(str);
		get_next_line(0, &str);
		nb_al[i] = ft_atoi(str);
		if (*str == '\0')
			break ;
		if (!ft_onlydigit(str) || i > 10000 ||
				nb_al[i] <= 0 || nb_al[i] > 10000)
		{
			free(str);
			return (NULL);
		}
		i++;
	}
	free(str);
	return (nb_al);
}

int				*ft_recup_from_file(int fd, int *nb_al)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strdup("bijour");
	while (ft_strcmp(str, ""))
	{
		free(str);
		get_next_line(fd, &str);
		nb_al[i] = ft_atoi(str);
		if (*str == '\0')
			break ;
		if (!ft_onlydigit(str) || i > 10000 ||
				nb_al[i] <= 0 || nb_al[i] > 10000)
		{
			free(str);
			return (NULL);
		}
		i++;
	}
	free(str);
	return (nb_al);
}

char			**alcu_recup_board(int fd)
{
	int		*nb_al;
	int		i;
	char	*str;
	char	**ret;

	if (!(nb_al = (int *)ft_memalloc(sizeof(int) * 10001)))
		return (NULL);
	i = 0;
	if (fd == 0)
		nb_al = ft_recup_from_input(nb_al);
	else
		nb_al = ft_recup_from_file(fd, nb_al);
	if (!nb_al)
		return (NULL);
	if (!(ret = fill_tab(nb_al)))
		return (NULL);
	free(nb_al);
	return (ret);
}

int				main(int argc, char **argv)
{
	int		fd;
	char	**tab;

	if (argc > 2)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	fd = 0;
	if (argc == 2)
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
		{
			ft_putstr_fd("ERROR\n", 2);
			return (0);
		}
	}
	if (!(tab = alcu_recup_board(fd)))
	{
		ft_putstr_fd("ERROR\n", 2);
		return (0);
	}
	alcu_ea_sport(tab);
	return (0);
}
