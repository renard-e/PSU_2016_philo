/*
** printf_error.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Mon Mar  6 10:52:09 2017 Gregoire Renard
** Last update Mon Mar  6 10:53:10 2017 Gregoire Renard
*/

#include "philo.h"

int			printf_error(char *str)
{
  printf("%s\n", str);
  return (ERROR);
}
