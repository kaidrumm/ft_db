#include "../includes/ft_db.h"

void		print_matching_records(t_table *t, int col, char *value)
{
	int		r;

	print_headers(t, stdin);
	r = 0;
	while (t->row_ids[r])
	{
		if (ft_strcmp(t->columns[col].content_array[r], value) == 0)
			print_row(t, 1, r);
		r++;
	}
}

void		search_query(t_table *t)
{
	char	*column;
	int		col_index;
	char	*value;

	column = ask_user("Which column do you want to search on?\n");
	col_index = find_matching_column(t, column);
	value = ask_user("Which value are you searching for?\n");

}
