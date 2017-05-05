/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:33:37 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 16:34:27 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void			graceful_exit(t_table *t)
{
	if (t->columns != NULL)
		free(t->columns);
	if (t->row_ids != NULL)
		free(t->row_ids);
	if (t->column_ids != NULL)
		free(t->column_ids);
	exit(0);
}

int				id_gen_r(t_table *t)
{
	if (g_row_counter == INT_MAX)
	{
		ft_putstr("Error, Row IDs have gone out of int range.\n");
		graceful_exit(t);
	}
	return (++g_row_counter);
}

int				id_gen_c(t_table *t)
{
	if (g_row_counter == INT_MAX)
	{
		ft_putstr("Error, Column IDs have gone out of int range.");
		graceful_exit(t);
	}
	return (++g_col_counter);
}

void			init_table(t_table *t)
{
	if (!(t->row_ids = (int *)malloc(sizeof(int) * g_height)))
		ft_error("Malloc error\n");
	bzero(t->row_ids, sizeof(int) * g_height);
	if (!(t->column_ids = (int *)malloc(sizeof(int) * g_width)))
		ft_error("Malloc error\n");
	bzero(t->column_ids, sizeof(int) * g_width);
	if (!(t->columns = (t_column *)malloc(sizeof(t_column) * g_width)))
		ft_error("Malloc error\n");
}
