/*
** set_cpt_flag.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Mar  8 10:26:49 2017 Gregoire Renard
** Last update Wed Mar  8 11:11:57 2017 Gregoire Renard
*/

#include "philo.h"

int			set_cpt_flag(int cpt, char **argv)
{
  if (argv[cpt] == NULL)
    return (ERROR);
  while (argv[cpt] != NULL && argv[cpt][0] != '-')
    cpt++;
  if (argv[cpt] == NULL)
    return (ERROR);
  return (cpt);
}
