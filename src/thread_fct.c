/*
** thread_fct.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Fri Mar 10 15:13:57 2017 Gregoire Renard
** Last update Mon Mar 27 22:06:55 2017 Gregoire Renard
*/

#include "philo.h"

int			join_thread(pthread_t *tab_thread,
				    t_info *info,
				    t_list *list)
{
  int			cpt;

  cpt = 0;
  while (cpt != info->p[1])
    {
      if ((pthread_join(tab_thread[cpt], NULL)) != 0)
	return (-1);
      cpt++;
      list = list->next;
    }
  return (0);
}

int			init_thread(pthread_t **tab_thread,
				    t_info *info,
				    t_list *list)
{
  int			cpt;

  if (((*tab_thread) = malloc(sizeof(pthread_t) * info->p[1])) == NULL)
    return (-1);
  cpt = 0;
  while (cpt != info->p[1])
    {
      if ((pthread_create(&(*tab_thread)[cpt], NULL, play, list)) != 0)
	return (-1);
      cpt++;
      list = list->next;
    }
  return (0);
}
