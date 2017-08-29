/*
** set_info.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
** 
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
** 
** Started on  Wed Mar  8 10:18:20 2017 Gregoire Renard
** Last update Tue Mar 14 17:51:43 2017 Gregoire Renard
*/

#include "philo.h"

void			set_info_first(t_info *info)
{
  info->p[0] = -1;
  info->p[1] = -1;
  info->e[0] = -1;
  info->e[1] = -1;
}

static int		ident_flag(char **argv, int cpt, t_info *info)
{
  if ((strcmp(argv[cpt], "-p")) == 0)
    {
      if ((remp_p(argv, cpt, info)) == ERROR)
	return (ERROR);
    }
  else if ((strcmp(argv[cpt], "-e")) == 0)
    {
      if ((remp_e(argv, cpt, info)) == ERROR)
	return (ERROR);
    }
  else
    return (ERROR);
  return (SUCCESS);
}

int			set_info_second(t_info *info, char **argv)
{
  int			cpt;
  int			enter;

  cpt = 0;
  enter = 0;
  while (enter != 2)
    {
      if ((cpt = set_cpt_flag(cpt, argv)) == ERROR)
	return (printf_error("Error : need more flag or flag not found"));
      if ((strlen(argv[cpt])) > 2 || (ident_flag(argv, cpt, info)) == ERROR)
	return (printf_error("Error : bad flag or bad value for flag"));
      enter++;
      cpt++;
    }
  return (SUCCESS);
}
