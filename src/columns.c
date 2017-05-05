/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   columns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:58:57 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 16:19:31 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void			delete_column(t_table *t)
{
	char	*response;
	int		c;

	response = ask_user("Which column would you like to delete?");
	c = find_matching_column(t, response);
	if (c == -1)
		return ;
	t->column_ids[c] = -1;
	fill_with_zeros(t, c);
}

static int		first_empty_column(t_table *t)
{
	int		i;

	i = 0;
	while (i < g_width)
	{
		if (t->column_ids[i] == 0 || t->column_ids[i] == -1)
			return (i);
		i++;
	}
	return (-1);
}

void			fill_with_zeros(t_table *t, int c)
{
	int		r;

	r = 0;
	while (t->row_ids[r])
	{
		t->columns[c].content_array[r] = "0";
		r++;
	}
}

void			add_column(t_table *t, char *name)
{
	int			index;
	t_column	*col;

	index = first_empty_column(t);
	if (index < 0)
	{
		ft_putstr("Columns are full\n");
		return ;
	}
	t->column_ids[index] = id_gen_c(t);
	col = &(t->columns[index]);
	col->name = name;
	col->content_array = (char **)malloc(sizeof(char *) * TABLE_SIZE);
	fill_with_zeros(t, index);
}
