#include "../includes/ft_db.h"

// void		print_matching_records(t_table *t, int col, char *value)
// {
// 	int		r;

// 	print_headers(t, stdout);
// 	r = 0;
// 	while (t->row_ids[r])
// 	{
// 		if (ft_strcmp(t->columns[col].content_array[r], value) == 0)
// 			print_row(t, 1, r);
// 		r++;
// 	}
// }

void		search_query(t_table *t)
{
	char	*column;
	int		col_index;
	char	*value;
	int		r;

	column = ask_user("Which column heading do you want to search under?\n");
	col_index = find_matching_column(t, column);
	if (col_index == -1)
		return ;
	value = ask_user("Which value are you searching for?\n");
	print_headers(t, stdout);
	printf("Searching on column %s\n", t->columns[col_index].name);
	r = 0;
	while (t->row_ids[r])
	{
		printf("Comparing to value %s\n", t->columns[col_index].content_array[r]);
		if (ft_strcmp(t->columns[col_index].content_array[r], value) == 0)
			print_row(t, 1, r);
		r++;
	}
}
