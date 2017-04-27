#include "../includes/ft_db.h"

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

void			add_column(t_table *t, char type, char *name)
{
	int			index;
	t_column	*col;

	index = first_empty_column(t);
	if (index < 0)
		ft_error("Table columns are full\n");
	t->column_ids[index] = index;
	col = &(t->columns[index]);
	col->content_type = type;
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
	col->name = name;
}

void			init_table(t_table *t)
{
	t->column_ids = (int *)malloc(sizeof(int) * TABLE_SIZE);
	t->columns = (t_column *)malloc(sizeof(t_column) * TABLE_SIZE);
}
