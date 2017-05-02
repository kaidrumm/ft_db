#include "../includes/ft_db.h"

void		print_headers(t_table *t, FILE *fp)
{
	int		c;
	int		fd;

	if (!fp)
		fp = stdout;
	fd = fileno(fp);
	c = 0;
	while (c < TABLE_SIZE && (t->column_ids[c] != 0))
	{
		ft_putstr_fd(t->columns[c].name, fd);
		ft_putchar_fd(',', fd);
		c++;
	}
	ft_putchar_fd('\n', fd);
}

void		print_row(t_table *t, int fd, int r)
{
	int		c;

	c = 0;
	ft_putstr_fd(ft_itoa(t->row_ids[r]), fd);
	ft_putchar_fd(',', fd);
	while (c < TABLE_SIZE && t->column_ids[c] != 0)
	{
		//printf("Trying to print the value at %i, %i\n", r, c);
		ft_putstr_fd(t->columns[c].content_array[r], fd);
		ft_putchar_fd(',', fd);
		c++;
	}
	r++;
	ft_putchar_fd('\n', fd);
}

void		print_table(t_table *t, int fd)
{
	int			r;
	FILE		*output;

	if (fd == 1)
		output = stdout;
	else
	{
		output = fopen(g_filename, "w+");
		fd = fileno(output);
	}
	print_headers(t, output);
	r = 0;
	while (r < TABLE_SIZE && t->row_ids[r] != 0)
	{
		if (t->row_ids[r] > 0)
			print_row(t, fd, r);
		r++;
		// c = 0;
		// ft_putstr_fd(ft_itoa(t->row_ids[r]), fd);
		// ft_putchar_fd(',', fd);
		// while (c < TABLE_SIZE && t->column_ids[c] != 0)
		// {
		// 	//printf("Trying to print the value at %i, %i\n", r, c);
		// 	ft_putstr_fd(t->columns[c].content_array[r], fd);
		// 	ft_putchar_fd(',', fd);
		// 	c++;
		// }
		// r++;
		// ft_putchar_fd('\n', fd);
	}
}
