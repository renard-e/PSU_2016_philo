/*
** xlock.c for philo in /media/rodrigue/1aa9b3b8-3e24-4ea9-9b0d-d57254b2d1b9/rodrigue.rene/Cours/Semestre_4/System_Unix/PSU_2016_philo/files_fourni
**
** Made by Rodrigue René
** Login   <rodrigue.rene@epitech.eu>
**
** Started on  Thu Mar  9 14:25:05 2017 Rodrigue René
** Last update Fri Mar 10 14:58:47 2017 Rodrigue René
*/

#include "philo.h"

void    xlocker(pthread_mutex_t *lockl)
{
  pthread_mutex_lock(lockl);
  lphilo_take_chopstick(lockl);
}

void    dexlocker(pthread_mutex_t *lockl)
{
  pthread_mutex_unlock(lockl);
  lphilo_release_chopstick(lockl);
}
