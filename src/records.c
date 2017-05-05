/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   records.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:58:49 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 13:51:18 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void			delete_record(t_table *t)
{
	char	*record_string;
	int		ID;
	int		c;

	record_string = ask_user("What is the ID of the record to delete?");
	ID = find_matching_record(t, atoi(record_string));
	t->row_ids[ID] = -1;
	c = 0;
	while (t->column_ids[c])
	{
		t->columns[c].content_array[ID] = NULL;
		c++;
	}
}

int				find_matching_record(t_table *t, int id)
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

void			update_value(t_table *t)
{
	char	*ID_name;
	char	*column_name;
	char	*newvalue;
	int		row_id;
	int		column_number;

	ID_name = ask_user("Please type the ID of the record you'd like to update");
	column_name = ask_user("Which column would you like to update?"
		"Please type the exact name");
	newvalue = ask_user("What new value would you like to insert?");
	row_id = find_matching_record(t, atoi(ID_name));
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

void			add_record_from_file(t_table *t, int r, char **list, int option)
{
	int		c;
	int		l;
	long	id;
	char	*errptr;

	// printf("Adding record %i, option %i\n", r, option);
	if (option == 0)
	{
		t->row_ids[r] = id_gen_r();
		l = 0;
	}
	else
	{
		id = strtol(list[0], &errptr, 10);
		if (errptr == list[0])
		    ft_error("Invalid ID format, please use only digits\n");
		else if (*errptr != '\0')
			ft_error("ID out of range\n");
		id = ft_atoi(list[0]);
		t->row_ids[r] = id;
		if (id > g_row_counter)
			g_row_counter = id;
		l = 1;
	}
	c = 0;
	while (list[l])
	{
		if (t->column_ids[c] == 0)
			ft_error("More content columns than headings."
				"I don't handle parens or quotes\n");
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
	printf("Found an empty row at %i\n", j);
	if (j < 0)
		ft_error("All rows are full\n");
	t->row_ids[j] = id_gen_r();
	while (i < g_width && t->column_ids[i] > 0)
	{
		title = t->columns[i].name;
		value = ask_user(title);
		t->columns[i].content_array[j] = value;
		i++;
	}
}
