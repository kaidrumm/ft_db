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

int 			g_row_counter;
int				g_col_counter;
char			*g_filename;

typedef struct	s_date
{
	int			time;
	int			day;
	int			month;
	int			year;
}				t_date;

typedef struct	s_column
{
	// int			*id_array;
	char		content_type;
	char		*name;
	char		**content_array;
}				t_column;

typedef struct	s_table
{
	int			row_ids[TABLE_SIZE];
	int			column_ids[TABLE_SIZE];
	t_column	*columns;
}				t_table;

int				find_matching_record(t_table *t, int id);
int				find_matching_column(t_table *t, char *name);
void			delete_record(t_table *t);
void			update_value(t_table *t);
void			graceful_exit(t_table *t);
int				id_gen_c(void);
int				id_gen_r(void);
void			print_table(t_table *t, int fd);
void			init_table(t_table *t);
void 			add_column_details(t_table *t);
void			add_column(t_table *t, char type, char *name);
void			add_record_from_file(t_table *t, int r, char **list);
//void			add_record_details(t_table *t);
void			add_record(t_table *t);
char			*ask_user(char *question);
void			menu(t_table *t);
void			load_from_file(t_table *t);

#endif
