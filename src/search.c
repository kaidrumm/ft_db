#include "../includes/ft_db.h"

int		find_matching_record(t_table *t, int id)
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

int		find_matching_column(t_table *t, char *name)
{
	int		index;

	index = 0;
	while (t->column_ids[index])
	{
		if (ft_strcmp(t->columns[index].name, name) == 0)
			return (index);
		index++;
	}
	return (-1);
}
