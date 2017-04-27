#include "../includes/ft_db.h"

static void	print_headers(t_table *t)
{
	int		c;

	printf("Print headers\n");
	c = 0;
	while (c < TABLE_SIZE && (t->column_ids[c] != 0))
	{
		ft_putstr(t->columns[c].name);
		ft_putchar('\t');
		c++;
	}
	ft_putchar('\n');
	exit(0);
}

void		print_table(t_table *t)
{
	int			r;
	// int			c;
	// t_column	*current;

	print_headers(t);
	r = 0;
	// while (r < TABLE_SIZE)
	// {
	// 	c = 0;
	// 	while (c < TABLE_SIZE)
	// 	{
	// 		t->columns[c].content_array[r];
	// 		c++;
	// 	}
	// 	r++;
	// }
}
