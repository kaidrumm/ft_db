/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 15:04:12 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 16:34:32 by kdrumm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void		print_headers(t_table *t, FILE *fp)
{
	int		c;
	int		fd;

	if (!fp)
		fp = stdout;
	fd = fileno(fp);
	ft_putstr_fd("ID,", fd);
	c = 0;
	while (c < g_width && (t->column_ids[c] != 0))
	{
		if (t->column_ids[c] == -1)
		{
			c++;
			continue ;
		}
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
	while (c < g_width && t->column_ids[c] != 0)
	{
		if (t->column_ids[c] == -1)
		{
			c++;
			continue ;
		}
		if (t->columns[c].content_array[r] == NULL)
			ft_putstr_fd("0", fd);
		else
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
	{
		ft_putchar('\n');
		output = stdout;
	}
	else
	{
		output = fopen(g_filename, "w+");
		fd = fileno(output);
	}
	print_headers(t, output);
	r = 0;
	while (r < g_height && t->row_ids[r] != 0)
	{
		if (t->row_ids[r] > 0)
			print_row(t, fd, r);
		r++;
	}
}
