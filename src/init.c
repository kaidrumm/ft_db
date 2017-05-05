/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:29:40 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 13:38:05 by kdrumm           ###   ########.us       */
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
	printf("Init table. g_width is %i and g_height is %i\n", g_width, g_height);
	if (!(t->row_ids = (int *)malloc(sizeof(int) * g_height)))
		ft_error("Malloc error\n");
	bzero(t->row_ids, sizeof(int) * TABLE_SIZE);
	printf("row ids zerod\n");
	if (!(t->column_ids = (int *)malloc(sizeof(int) * g_width)))
		ft_error("Malloc error\n");
	bzero(t->column_ids, sizeof(int) * TABLE_SIZE);
	printf("column ids zerod\n");
	if (!(t->columns = (t_column *)malloc(sizeof(t_column) * TABLE_SIZE)))
		ft_error("Malloc error\n");
	printf("Completed init\n");
	printf("columns zerod\n");
}
