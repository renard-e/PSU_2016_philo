/*
** list_fct.c for  in /home/renard_e/2/systeme_unix_concurence/PSU_2016_philo/src
**
** Made by Gregoire Renard
** Login   <renard_e@epitech.net>
**
** Started on  Thu Mar  9 12:50:14 2017 Gregoire Renard
** Last update Tue Mar 14 17:51:03 2017 Gregoire Renard
*/

#include "philo.h"

void				print_list(t_list *list, t_info *info)
{
  while (list->indic != info->p[1] - 1)
    {
      printf("elem n°%i    %d\n", list->indic, list->state);
      list = list->next;
    }
  printf("elem n°%i                      %d\n\n", list->indic, list->state);
  printf("TEST ---------------------- PREV\n\n");
  while (list->indic != 0)
    {
      printf("elem n°%i     %d\n", list->indic, list->state);
      list = list->prev;
    }
  printf("elem n°%i    %d\n", list->indic, list->state);
}

void				free_list(t_list *list, t_info *info)
{
  t_list			*tmp;

  tmp = list;
  while (tmp->indic != info->p[1] - 1)
    {
      list = list->next;
      free(tmp);
      tmp = list;
    }
  free(list);
}

static void			set_elem(t_list **elem, t_list **root, int cpt)
{
  t_list			*tmp;

  tmp = (*root);
  if ((*root) == NULL)
    {
      (*elem)->next = (*elem);
      (*elem)->prev = (*elem);
      (*root) = (*elem);
    }
  else
    {
      while (tmp->indic != (cpt - 1))
	tmp = tmp->next;
      tmp->next = (*elem);
      (*elem)->prev = tmp;
      (*elem)->next = (*root);
      (*root)->prev = (*elem);
    }
}

static int			add_elem(t_list **root, int cpt)
{
  t_list			*elem;

  if ((elem = malloc(sizeof(*elem))) == NULL)
    return (ERROR);
  elem->indic = cpt;
  elem->state = UNDEFINED;
  pthread_mutex_init (&elem->mutexm, NULL);
  set_elem(&elem, root, cpt);
  return (SUCCESS);
}

t_list				*create_all_philo(t_info *info)
{
  t_list			*root;
  int				cpt;

  root = NULL;
  cpt = 0;
  while (cpt != info->p[1])
    {
      if ((add_elem(&root, cpt)) == ERROR)
	return (NULL);
      cpt++;
    }
  return (root);
}
