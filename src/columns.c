#include "../includes/ft_db.h"

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
		printf("Checking column %i\n", i);
		if (t->column_ids[i] == 0)
			return (i);
		i++;
	}
	return (-1);
}

void			add_column(t_table *t, char type, char *name)
{
	int			index;
	t_column	*col;

	printf("Add column %s\n", name);
	index = first_empty_column(t);
	if (index < 0)
		ft_error("Table columns are full\n");
	t->column_ids[index] = id_gen();
	printf("Assigned id %i to column %i\n", t->column_ids[index], index);
	col = &(t->columns[index]);
	printf("Column pointer %p\n", col);
	col->content_type = type;
	col->name = name;
	printf("Column type is %c and name is %s\n", col->content_type, col->name);
	if (type == 'i')
		col->content_array = malloc(sizeof(int) * TABLE_SIZE);
	else if (type == 'c')
		col->content_array = malloc(sizeof(char) * TABLE_SIZE);
	else if (type == 's')
	{
		printf("It's a string\n");
		col->content_array = malloc(sizeof(char *) * TABLE_SIZE);
	}
	else if (type == 'd')
		col->content_array = malloc(sizeof(t_date) * TABLE_SIZE);
	else
		ft_error("Content type not available\n");
	col->name = name;
}