/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:58:49 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 15:05:56 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void		search_query(t_table *t)
{
	char	*column;
	int		col_index;
	char	*value;
	int		r;

	column = ask_user("Which column heading do you want to search under?");
	col_index = find_matching_column(t, column);
	if (col_index == -1)
		return ;
	value = ask_user("Which value are you searching for?");
	printf("Searching on column %s\n\n", t->columns[col_index].name);
	print_headers(t, stdout);
	r = 0;
	while (t->row_ids[r])
	{
		//printf("Comparing to value %s\n", t->columns[col_index].content_array[r]);
		if (t->columns[col_index].content_array[r] != NULL && \
			ft_strcmp(t->columns[col_index].content_array[r], value) == 0)
			print_row(t, 1, r);
		r++;
	}
}
