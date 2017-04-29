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
}

void		print_table(t_table *t)
{
	int			r;
	int			c;
	// t_column	*current;

	print_headers(t);
	r = 0;
	while (r < TABLE_SIZE && t->row_ids[r] != 0)
	{
		c = 0;
		while (c < TABLE_SIZE && t->column_ids[c] != 0)
		{
			//printf("Trying to print the value at %i, %i\n", r, c);
			ft_putstr(t->columns[c].content_array[r]);
			ft_putchar('\t');
			c++;
		}
		r++;
		ft_putchar('\n');
	}
}
