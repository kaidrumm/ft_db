#include "../includes/ft_db.h"

void			graceful_exit(t_table *t)
{
	if (t->columns != NULL)
		free(t->columns);
	exit(0);
}

int				id_gen(void)
{
	g_id_counter++;
	return (g_id_counter);
}

void			init_table(t_table *t)
{
	//t->column_ids = (int *)malloc(sizeof(int) * TABLE_SIZE);
	bzero(t->column_ids, sizeof(int) * TABLE_SIZE);
	//t->row_ids = (int *)malloc(sizeof(int) * TABLE_SIZE);
	bzero(t->row_ids, sizeof(int) * TABLE_SIZE);
	t->columns = (t_column *)malloc(sizeof(t_column) * TABLE_SIZE);
}
