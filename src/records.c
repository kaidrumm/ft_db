#include "../includes/ft_db.h"

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

void	add_record_from_file(t_table *t, int r, char **list)
{
	int		c;

	printf("Adding record %i\n", r);
	c = 0;
	while (list[c])
	{
		t->row_ids[r] = id_gen();
		t->columns[c].content_array[r] = ft_strdup(list[c]);
		printf("Assigned %s to %i, %i\n", t->columns[c].content_array[r], r, c);
		c++;
	}
}

void	add_record(t_table *t)
{
	int		i;
	int		j;
	char	*value;
	char	*title;

	i = 0;
	j = first_empty_row(t);
	t->row_ids[j] = id_gen();
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
