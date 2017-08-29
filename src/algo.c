/*
** algo.c for philo in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_philo/src
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Thu Mar  9 16:39:36 2017 Rodrigue René
** Last update Tue Mar 21 09:50:22 2017 Gregoire Renard
*/

#include "philo.h"

pthread_mutex_t       g_mutex = PTHREAD_MUTEX_INITIALIZER; // peut etre ici

static void		thinking_fct(t_play *play)
{
  xlocker(&play->list->mutexm);
  lphilo_think();
  dexlocker(&play->list->mutexm);
}

static void		eating_fct(t_play *play)
{
  xlocker(&play->list->mutexm);
  xlocker(&play->list->prev->mutexm);
  lphilo_eat();
  dexlocker(&play->list->mutexm);
  dexlocker(&play->list->prev->mutexm);
  play->eating++;
  if (play->eating == (g_occurence - 1))
    g_max_eating++;
}

static int		choice_fct(t_play *play)
{
  if (play->state == THINKING && play->eating != (g_occurence - 1))
    thinking_fct(play);
  else if (play->state == EATING && play->eating != (g_occurence - 1))
    eating_fct(play);
  else if ((play->state == EATING && g_occurence == 1) ||
	   (g_max_eating == g_philo && g_stop != 1))
    {
      g_stop = 1;
      eating_fct(play);
    }
  else if (play->eating == (g_occurence - 1))
    {
      thinking_fct(play);
      ++play->i;
      if (play->i > 12)
	{
	  pthread_mutex_unlock(&g_mutex);
	  pthread_exit(NULL);
	  return (ERROR);
	}
    }
  else
    lphilo_sleep();
  return (SUCCESS);
}

void			*play(void *arg)
{
  t_play		play;

  init_play(&play, arg);
  while (g_stop == 0)
    {
      pthread_mutex_lock(&g_mutex);
      play.state = play.tmp->state;
      if ((choice_fct(&play)) == ERROR)
	return (NULL);
      ++play.cpt;
      play.tmp = play.tmp->prev;
      pthread_mutex_unlock(&g_mutex);
    }
  pthread_exit(NULL);
  return (NULL);
}

int			algo(t_list *list, t_info *info)
{
  pthread_t		*tab_thread;

  g_occurence = info->e[1];
  g_stop = 0;
  g_philo = info->p[1];
  fill_first(&list, info);
  if (g_philo == 1)
    return (1);
  if ((init_thread(&tab_thread, info, list)) == -1)
    return (-1);
  if ((join_thread(tab_thread, info, list)) == -1)
    return (-1);
  free(tab_thread);
  return (0);
}
