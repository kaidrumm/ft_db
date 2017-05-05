#include "../includes/ft_db.h"

void			delete_column(t_table *t)
{
	char	*response;
	int		c;

	response = ask_user("Which column would you like to delete?\n");
	c = find_matching_column(t, response);
	if (c == -1)
		return ;
	t->column_ids[c] = -1;
	fill_with_zeros(t, c);
}

int				find_matching_column(t_table *t, char *name)
{
	int		index;

	index = 0;
	while (t->column_ids[index])
	{
		if (ft_strcmp(t->columns[index].name, name) == 0)
			return (index);
		index++;
	}
	printf("I didn't find a column matching that name\n");
	return (-1);
}

void 			add_column_details(t_table *t)
{
	char	*name;
	char	*datatype;

	name = ask_user("Please type the column name");
	datatype = ask_user("What type of data is this?");
	add_column(t, datatype[0], name);
}

static int		first_empty_column(t_table *t)
{
	int		i;

	i = 0;
	while (i < TABLE_SIZE)
	{
		if (t->column_ids[i] == 0)
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

void			add_column(t_table *t, char type, char *name)
{
	int			index;
	t_column	*col;

	index = first_empty_column(t);
	if (index < 0)
		ft_error("Table columns are full\n");
	t->column_ids[index] = id_gen_c();
	printf("Add column %s with id %i\n", name, t->column_ids[index]);
	col = &(t->columns[index]);
	col->content_type = type;
	col->name = name;
	if (type == 'i')
		col->content_array = malloc(sizeof(int) * TABLE_SIZE);
	else if (type == 'c')
		col->content_array = malloc(sizeof(char) * TABLE_SIZE);
	else if (type == 's')
		col->content_array = malloc(sizeof(char *) * TABLE_SIZE);
	else if (type == 'd')
		col->content_array = malloc(sizeof(t_date) * TABLE_SIZE);
	else
		ft_error("Content type not available\n");
	fill_with_zeros(t, index);
}
