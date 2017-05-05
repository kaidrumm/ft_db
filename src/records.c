/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   records.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:58:49 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 16:19:22 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void			delete_record(t_table *t)
{
	char	*record_string;
	int		id;
	int		c;

	record_string = ask_user("What is the ID of the record to delete?");
	id = find_matching_record(t, atoi(record_string));
	t->row_ids[id] = -1;
	c = 0;
	while (t->column_ids[c])
	{
		t->columns[c].content_array[id] = NULL;
		c++;
	}
}

static int		first_empty_row(t_table *t)
{
	int		j;

	j = 0;
	while (j < g_height)
	{
		if (t->row_ids[j] == 0)
			return (j);
		j++;
	}
	return (-1);
}

static void		read_ids(t_table *t, char **list, int r)
{
	long	id;
	char	*errptr;

	id = strtol(list[0], &errptr, 10);
	if (errptr == list[0])
		ft_error("Invalid ID format, please use only digits\n");
	else if (*errptr != '\0')
		ft_error("ID out of range\n");
	id = ft_atoi(list[0]);
	if (id > INT_MAX || id < 0)
		ft_error("ID out of range, please use integer IDs\n");
	t->row_ids[r] = id;
	if (id > g_row_counter)
		g_row_counter = id;
}

void			add_record_from_file(t_table *t, int r, char **list, int option)
{
	int		c;
	int		l;

	l = 0;
	if (option == 0)
		t->row_ids[r] = id_gen_r(t);
	else
	{
		read_ids(t, list, r);
		l = 1;
	}
	c = 0;
	while (list[l] && c < g_width)
	{
		if (t->column_ids[c] == 0)
		{
			ft_putstr("More content columns than headings. "
				"I don't handle parens or quotes\n");
			return ;
		}
		t->columns[c].content_array[r] = ft_strdup(list[l]);
		c++;
		l++;
	}
}

void			add_record(t_table *t)
{
	int		i;
	int		j;
	char	*value;
	char	*title;

	i = 0;
	j = first_empty_row(t);
	if (j < 0)
	{
		ft_putstr("All rows are full\n");
		return ;
	}
	t->row_ids[j] = id_gen_r(t);
	while (i < g_width && t->column_ids[i] > 0)
	{
		title = t->columns[i].name;
		value = ask_user(title);
		t->columns[i].content_array[j] = value;
		i++;
	}
}
