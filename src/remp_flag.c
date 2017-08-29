/*
** remp_flag.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Mar  8 10:45:14 2017 Gregoire Renard
** Last update Tue Mar 14 17:50:20 2017 Gregoire Renard
*/

#include "philo.h"

static int		check_arg(char *str)
{
  int			cpt;

  cpt = 0;
  if (str == NULL)
    return (ERROR);
  if (strlen(str) > 9)
    return (ERROR);
  while (str[cpt] != '\0')
    {
      if (str[cpt] >= '0' && str[cpt] <= '9')
	cpt++;
      else
	return (ERROR);
    }
  return (SUCCESS);
}

int			remp_p(char **argv, int cpt, t_info *info)
{
  if (info->p[0] != -1)
    return (ERROR);
  info->p[0] = 1;
  if ((check_arg(argv[cpt + 1])) == ERROR)
    return (ERROR);
  info->p[1] = atoi(argv[cpt + 1]);
  return (SUCCESS);
}

int			remp_e(char **argv, int cpt, t_info *info)
{
  if (info->e[0] != -1)
    return (ERROR);
  info->e[0] = 1;
  if ((check_arg(argv[cpt + 1])) == ERROR)
    return (ERROR);
  info->e[1] = atoi(argv[cpt + 1]);
  return (SUCCESS);
}
