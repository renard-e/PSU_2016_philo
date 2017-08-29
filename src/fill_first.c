/*
** fill_first.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Tue Mar 14 18:02:38 2017 Gregoire Renard
** Last update Tue Mar 14 18:07:10 2017 Gregoire Renard
*/

#include "philo.h"

static void		impaire_fill(t_info *info, t_list **list)
{
  int			i;

  i = 0;
  while (i < (info->p[1] - 2))
    {
      if ((i % 2) == 1)
	(*list)->state = RESTING;
      else
	(*list)->state = EATING;
      i++;
      (*list) = (*list)->next;
    }
  (*list)->state = THINKING;
  (*list) = (*list)->next;
  (*list)->state = RESTING;
}

static void		paire_fill(t_info *info, t_list **list)
{
  int			i;

  i = 0;
  while (i < info->p[1])
    {
      if ((i % 2) == 1)
	(*list)->state = RESTING;
      else
	(*list)->state = EATING;
      i++;
      (*list) = (*list)->next;
    }
}

void			fill_first(t_list **list, t_info *info)
{
  while ((*list)->indic != 0)
    (*list) = (*list)->next;
  if (info->p[1] == 1)
    (*list)->state = THINKING;
  else if ((info->p[1] % 2) == 1)
    impaire_fill(info, list);
  else
    paire_fill(info, list);
}
