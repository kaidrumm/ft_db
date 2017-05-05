/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 10:59:09 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 15:23:43 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"


// static void		open_file(t_table *t)
// {

// }

void			load_from_file(t_table *t)
{
	FILE	*file_ptr;
	char	*line;
	char 	**list;
	int		option;
	int		ret;
	int		r;
	int		c;

	// printf("filename is %s\n", g_filename);
	if ((file_ptr = fopen(g_filename, "r+")) == NULL)
		ft_error("Error opening file\n");
	option = ask_user_yn("Does this sheet have an ID column on the left?");
	if (option == 0)
		printf("We will generate IDs for you\n");
	c = option;
	line = NULL;
	ret = get_next_line(fileno(file_ptr), &line);
	// printf("Gnl returned %i and line is %s\n", ret, line);
	if (!line || ft_strcmp(line, "") == 0)
		ft_error("Error reading file\n");
	if (ret)
	{
		// printf("Got line %s from fptr %i\n", line, fileno(file_ptr));
		list = ft_strsplit(line, ',');
		while (list[c])
		{
			// printf("Attempting to add column %s of %c\n", list[c], c);
			add_column(t, list[c]);
			c++;
			if (c > g_width)
			{
				printf("Truncating sheet.\n");
				break ;
			}
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
			printf("Sorry, there are too many rows to load. Truncating.\n");
			break ;
		}
	}
	fclose(file_ptr);
}

static void		parse_arguments(t_table *t, int ac, char **av)
{
	int			i;

	i = 1;
	while (i < ac)
	{
		// printf("Checking av[%i]. av[i] is %s and av[i+1] is %s. *av[i+1] is %c\n", i, av[i], av[i + 1], *av[i+1]);
		if (ft_strcmp(av[i], "-help") == 0)
			usage(t);
		else if (ft_strcmp(av[i], "-f") == 0)
		{	
			g_filename = ft_strdup(av[i + 1]);
			// printf("set filename as %s\n", g_filename);
		}
		else if (ft_strcmp(av[i], "-h") == 0 && ft_isdigit((int)*(av[i + 1])))
		{
			g_height = atoi(av[i + 1]);
			// printf("set height as %i\n", g_height);
		}
		else if (ft_strcmp(av[i], "-w") == 0 && ft_isdigit((int)*(av[i + 1])))
		{
			g_width = atoi(av[i + 1]);
			// printf("set width as %i\n", g_width);
		}
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
