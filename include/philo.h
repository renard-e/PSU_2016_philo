/*
** philo.h for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/include
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Mon Mar  6 09:06:32 2017 Gregoire Renard
** Last update Thu Mar 16 16:13:17 2017 Gregoire Renard
*/

#ifndef PHILO_H_
#define PHILO_H_

# define SUCCESS 0
# define ERROR -1

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include "extern.h"

int			g_occurence;
int			g_stop;
int			g_philo;
int			g_max_eating;

typedef enum		e_state
  {
    UNDEFINED,
    EATING,
    RESTING,
    THINKING
  }			t_state;

typedef struct		s_info
{
  int			p[2];
  int			e[2];
}			t_info;

typedef struct		s_list
{
  int			indic;
  int			eating;
  int			chopstick;
  t_state		state;
  pthread_mutex_t       mutexm;
  struct s_list		*next;
  struct s_list		*prev;
}			t_list;

typedef struct		s_play
{
  t_list		*list;
  t_list		*tmp;
  int			cpt;
  t_state		state;
  int			eating;
  int			i;
}			t_play;

int			printf_error(char *str);
int			remp_info(t_info *info, int argc, char **argv);
void			set_info_first(t_info *info);
int			set_info_second(t_info *info, char **argv);
int			set_cpt_flag(int cpt, char **argv);
int			remp_p(char **argv, int cpt, t_info *info);
int			remp_e(char **argv, int cpt, t_info *info);
void			print_list(t_list *list, t_info *info);
void			free_list(t_list *list, t_info *info);
t_list			*create_all_philo(t_info *info);

int			algo(t_list *list, t_info *info);
void			xlocker(pthread_mutex_t *lockl);
void			dexlocker(pthread_mutex_t *lockl);
int			init_thread(pthread_t **tab_thread,
				    t_info *info,
				    t_list *list);
void			*play(void *arg);
int			join_thread(pthread_t *tab_thread,
				    t_info *info,
				    t_list *list);
void			fill_first(t_list **list, t_info *info);
void			init_play(t_play *play, void *arg);
#endif /* !PHILO_H_ */
