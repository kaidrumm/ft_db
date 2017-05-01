#include "../includes/ft_db.h"

// void			update_value(int r, int c, char *new)
// {
	
// 	char	*newvalue;

// 	newvalue = ask_user()
// }

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

void			add_record_from_file(t_table *t, int r, char **list)
{
	int		c;

	printf("Adding record %i\n", r);
	if (list[0] == 0)
		t->row_ids[r] = id_gen_r();
	else
		t->row_ids[r] = ft_atoi(list[0]);
	c = 1;
	while (list[c])
	{
		t->columns[c - 1].content_array[r] = ft_strdup(list[c]);
		printf("Assigned %s to %i, %i\n", t->columns[c - 1].content_array[r], r, c);
		c++;
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
