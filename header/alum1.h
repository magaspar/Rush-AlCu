/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   alum1.h                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tduverge <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/16 13:58:34 by tduverge     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/17 19:11:23 by tduverge    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ALUM1_H
# define ALUM1_H

# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include "libft.h"
# include <unistd.h>

# define BUFF_SIZE 8

typedef struct			s_save
{
	int					fd;
	char				*buf;
	struct s_save		*next;
}						t_save;

int						get_next_line(const int fd, char **line);
int						ft_onlydigit(char *str);
void					alcu_ea_sport(char **tab);
char					**fill_tab(int *nb_al);
void					print_tab(char **tab);
void					alcu_first_player(char **tab, char *p1, char *p2);
void					alcu_second_player(char **tab, char *p1, char *p2);
int						ft_count_matches(char **tab);
void					ft_remove(int n, char **tab);
void					alcu_player(char **tab);
void					alcu_ia(char **tab);
int						get_first(char **tab);
int						*ft_trans(char **tab);
int						*ft_trans_bis(int *itab);
int						ft_actual_line(int *itab);
int						ft_ask_matches(char *player, int last);
int						ft_ask_yes_no(char *question);
void					ft_putbatman(void);

#endif
