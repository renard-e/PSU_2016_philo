/*
** remp_info.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Mar  6 10:27:16 2017 Gregoire Renard
** Last update Tue Mar 14 17:51:26 2017 Gregoire Renard
*/

#include "philo.h"

int			remp_info(t_info *info, int argc, char **argv)
{
  if (argc != 5)
    return (printf_error("Usage : ./philo -p [philosopher] -e [occurence]"));
  set_info_first(info);
  if ((set_info_second(info, argv)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}
