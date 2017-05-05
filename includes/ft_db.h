/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:58:49 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 13:43:35 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

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

int				g_width;
int				g_height;
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
	char		*name;
	char		**content_array;
}				t_column;

typedef struct	s_table
{
	int			*row_ids;
	int			*column_ids;
	t_column	*columns;
}				t_table;

void			usage(void);
int				id_gen_c(void);
int				id_gen_r(void);
void			menu(t_table *t);
void			init_table(t_table *t);
void			add_record(t_table *t);
void			update_value(t_table *t);
void			search_query(t_table *t);
void			delete_column(t_table *t);
void			delete_record(t_table *t);
void			graceful_exit(t_table *t);
char			*ask_user(char *question);
void			load_from_file(t_table *t);
int				ask_user_yn(char *question);
void 			add_column_details(t_table *t);
void			print_table(t_table *t, int fd);
void			fill_with_zeros(t_table *t, int c);
void			print_headers(t_table *t, FILE *fp);
void			print_row(t_table *t, int fd, int r);
int				find_matching_record(t_table *t, int id);
int				find_matching_column(t_table *t, char *name);
void			add_column(t_table *t, char *name);
void			add_record_from_file(t_table *t, int r, char **list, int option);

#endif
