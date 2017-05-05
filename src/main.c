/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:59:09 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 13:53:45 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void			load_from_file(t_table *t)
{
	FILE	*file_ptr;
	char	*line;
	char 	**list;
	int		option;
	int		r;
	int		c;

	if (!(file_ptr = fopen(g_filename, "r+")))
		ft_error("Error opening file\n");
	option = ask_user_yn("Does this sheet have an ID column on the left?");
	if (option == 0)
	{
		printf("We will generate IDs for you\n");
		c = 0;
	}
	else
		c = 1;
	if (get_next_line(fileno(file_ptr), &line))
	{
		list = ft_strsplit(line, ',');
		while (list[c])
		{
			add_column(t, list[c]);
			c++;
		}
	}
	r = 0;
	while (get_next_line(fileno(file_ptr), &line))
	{
		list = ft_strsplit(line, ',');
		add_record_from_file(t, r, list, option);
		r++;
		if (r > g_width)
		{
			printf("Sorry, there are too many rows to load\n");
			break ;
		}
	}
	fclose(file_ptr);
}

static void		parse_arguments(int ac, char **av)
{
	int			i;

	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-h") == 0)
			usage();
		else if (ft_strcmp(av[i], "-f") == 0)
			g_filename = av[i + 1];
		else if (ft_strcmp(av[i], "-h") == 0 && ft_isdigit(*av[i + 1]))
			g_height = atoi(av[i + 1]);
		else if (ft_strcmp(av[i], "-w") == 0 && ft_isdigit(*av[i + 1]))
			g_width = atoi(av[i + 1]);
		else
		{
			usage();
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
		usage();
	parse_arguments(ac, av);
	init_table(&t);
	if (g_filename != NULL)
		load_from_file(&t);
	else
		g_filename = "ft_db.csv";
	while (1)
		menu(&t);
	return (0);
}
