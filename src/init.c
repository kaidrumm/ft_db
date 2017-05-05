/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:29:40 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 15:26:58 by kdrumm           ###   ########.us       */
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

int				id_gen_r(void)
{
	return (++g_row_counter);
}

int				id_gen_c(void)
{
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
