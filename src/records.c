#include "../includes/ft_db.h"

void			delete_record(t_table *t)
{
	char	*record_string;
	int		ID;
	int		c;

	record_string = ask_user("What is the ID of the record you'd like to update?\n");
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

	ID_name = ask_user("Please type the ID of the record you'd like to update\n");
	column_name = ask_user("Which column would you like to update? Please type the exact name\n");
	newvalue = ask_user("What new value would you like to insert?\n");
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
	while (j < TABLE_SIZE)
	{
		printf("Checking row %i\n", j);
		if (t->row_ids[j] == 0)
			return (j);
		j++;
	}
	return (-1);
}

void			add_record_from_file(t_table *t, int r, char **list, char *option)
{
	int		c;
	int		l;

	printf("Adding record %i\n", r);
	if (!ft_strcmp(option, "N"))
	{
		t->row_ids[r] = id_gen_r();
		l = 0;
	}
	else 
	{
		t->row_ids[r] = ft_atoi(list[0]);
		l = 1;
	}
	printf("Assigned ID %i to row %i\n", t->row_ids[r], r);
	c = 0;
	while (list[l])
	{
		t->columns[c].content_array[r] = ft_strdup(list[l]);
		printf("Assigned %s to %i, %i\n", t->columns[c].content_array[r], r, c);
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
	t->row_ids[j] = id_gen_r();
	printf("Assigned ID %i to row %i\n", t->row_ids[j], j);
	while (i < TABLE_SIZE && t->column_ids[i] > 0)
	{
		title = t->columns[i].name;
		printf("I recognize that you named this column %s\n", title);
		value = ask_user(title);
		t->columns[i].content_array[j] = value;
		printf("Assigned %s to column %i, content array %i\n", value, i, j);
		i++;
	}
}
