/*
** init_play.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Thu Mar 16 16:08:06 2017 Gregoire Renard
** Last update Thu Mar 16 16:08:51 2017 Gregoire Renard
*/

#include "philo.h"

void			init_play(t_play *play, void *arg)
{
  play->list = arg;
  play->cpt = 0;
  play->tmp = play->list;
  play->eating = 0;
  play->i = 0;
}

