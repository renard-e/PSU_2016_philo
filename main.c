/*
** main.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Mon Mar  6 09:05:11 2017 Gregoire Renard
** Last update Tue Mar 14 11:01:30 2017 Rodrigue René
*/

#include "philo.h"

int			main(int argc, char **argv)
{
  t_list		*list;
  t_info		info;

  if ((remp_info(&info, argc, argv)) == ERROR)
    return (ERROR);
  if ((list = create_all_philo(&info)) == NULL)
    return (ERROR);
  RCFStartup(argc, argv);
  algo(list, &info);
  free_list(list, &info);
  RCFCleanup();
  return (SUCCESS);
}
