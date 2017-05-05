/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:59:09 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 15:55:48 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

static void		rows_from_file(t_table *t, FILE *file_ptr, int option)
{
	int		r;
	char	*line;
	char	**list;

	line = NULL;
	r = 0;
	while (get_next_line(fileno(file_ptr), &line))
	{
		list = ft_strsplit(line, ',');
		add_record_from_file(t, r, list, option);
		r++;
		if (r > g_width)
		{
			ft_putstr("Sorry, there are too many rows to load. Truncating.\n");
			break ;
		}
	}
}

static void		columns_from_file(t_table *t, char *line, int c)
{
	char	**list;

	list = ft_strsplit(line, ',');
	while (list[c])
	{
		add_column(t, list[c]);
		c++;
		if (c > g_width)
		{
			ft_putstr("Truncating sheet.\n");
			break ;
		}
	}
}

static void		load_from_file(t_table *t)
{
	FILE	*file_ptr;
	char	*line;
	int		option;
	int		ret;

	if ((file_ptr = fopen(g_filename, "r+")) == NULL)
		ft_error("Error opening file\n");
	option = ask_user_yn("Does this sheet have an ID column on the left?");
	if (option == 0)
		ft_putstr("We will generate IDs for you\n");
	line = NULL;
	ret = get_next_line(fileno(file_ptr), &line);
	if (!line || ft_strcmp(line, "") == 0 || (ret < 0))
		ft_error("Error reading file\n");
	columns_from_file(t, line, option);
	rows_from_file(t, file_ptr, option);
	fclose(file_ptr);
}

static void		parse_arguments(t_table *t, int ac, char **av)
{
	int			i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-help") == 0)
			usage(t);
		else if (ft_strcmp(av[i], "-f") == 0)
			g_filename = ft_strdup(av[i + 1]);
		else if (ft_strcmp(av[i], "-h") == 0 && ft_isdigit((int)*(av[i + 1])))
			g_height = atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-w") == 0 && ft_isdigit((int)*(av[i + 1])))
			g_width = atoi(av[i + 1]);
		else
		{
			usage(t);
			exit(1);
		}
		i += 2;
	}
}

int				main(int ac, char **av)
{
	t_table		t;

	g_row_counter = 0;
	g_col_counter = 0;
	g_filename = NULL;
	g_width = TABLE_SIZE;
	g_height = TABLE_SIZE;
	if (ac > 7)
		usage(&t);
	parse_arguments(&t, ac, av);
	init_table(&t);
	if (g_filename != NULL)
		load_from_file(&t);
	else
		g_filename = "ft_db.csv";
	while (1)
		menu(&t);
	return (0);
}
