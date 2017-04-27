#ifndef FT_DB_H
# define FT_DB_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <sys/types.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

# define TABLE_SIZE 100

// int 		g_id_counter;

typedef struct	s_date
{
	int			time;
	int			day;
	int			month;
	int			year;
}				t_date;

typedef struct	s_column
{
	char		content_type;
	char		*name;
	void		*content_array;
}				t_column;

typedef struct	s_table
{
	int			*column_ids;
	t_column	*columns;
}				t_table;

void			print_table(t_table *t);
void			init_table(t_table *t);
void			add_column(t_table *t, char type, char *name);

#endif
