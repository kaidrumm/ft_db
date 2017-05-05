/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 16:04:26 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 16:34:37 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void		update_value(t_table *t)
{
	char	*id_name;
	char	*column_name;
	char	*newvalue;
	int		row_id;
	int		column_number;

	id_name = ask_user("Please type the ID of the record you'd like to update");
	column_name = ask_user("Which column would you like to update?"
		"Please type the exact name");
	newvalue = ask_user("What new value would you like to insert?");
	row_id = find_matching_record(t, atoi(id_name));
	if (row_id == -1)
	{
		printf("Sorry, that isn't a valid record ID\n");
		return ;
	}
	column_number = find_matching_column(t, column_name);
	if (column_number == -1)
	{
		printf("Sorry, that isn't a valid record ID\n");
		return ;
	}
	t->columns[column_number].content_array[row_id] = ft_strdup(newvalue);
}

int			find_matching_column(t_table *t, char *name)
{
	int		index;

	index = 0;
	while (t->column_ids[index])
	{
		if (ft_strcmp(t->columns[index].name, name) == 0)
			return (index);
		index++;
	}
	ft_putstr("I didn't find a column matching that name\n");
	return (-1);
}

int			find_matching_record(t_table *t, int id)
{
	int		index;

	index = 0;
	while (t->row_ids[index])
	{
		if (t->row_ids[index] == id)
			return (index);
		index++;
	}
	return (-1);
}

void		search_query(t_table *t)
{
	char	*column;
	int		col_index;
	char	*value;
	int		r;

	column = ask_user("Which column heading do you want to search under?");
	col_index = find_matching_column(t, column);
	if (col_index == -1)
		return ;
	value = ask_user("Which value are you searching for?");
	printf("Searching on column %s\n\n", t->columns[col_index].name);
	print_headers(t, stdout);
	r = 0;
	while (t->row_ids[r])
	{
		if (t->columns[col_index].content_array[r] != NULL && \
			ft_strcmp(t->columns[col_index].content_array[r], value) == 0)
			print_row(t, 1, r);
		r++;
	}
}
