#include "../includes/ft_db.h"


void		menu(t_table *t)
{
	char	buf[10];
	int		option;

	ft_putendl("What operation would you like to perform?\n\t"
		"[1] Add Column \n\t"
		"[2] Add Record\n\t"
		"[3] Update Value\n\t"
		"[4] Delete Record\n\t"
		"[5] Search by Value\n\t"
		"[6] Print Table\n\t"
		"[7] Exit");
	option = atoi(fgets(buf, sizeof(buf), stdin));
	if (option == 1)
		add_column_details(t);
	else if (option == 2)
		add_record(t);
	else if (option == 3)
		update_value(t);
	else if (option == 4)
		delete_record(t);
	else if (option == 5)
		search_query(t);
	else if (option == 6)
		print_table(t, 1);
	else if (option == 7)
	{
		print_table(t, 4);
		graceful_exit(t);
	}
	else
		ft_putendl("Sorry, that option isn't covered yet\n");
}

void		load_from_file(t_table *t)
{
	FILE	*file_ptr;
	char	*line;
	char 	**list;
	int		option;
	int		r;
	int		c;

	if (!(file_ptr = fopen(g_filename, "r+")))
		ft_error("Error opening file\n");
	option = ask_user_yn("Does this sheet have an ID column on the left? Y or N\n");
	printf("I heard option %i\n", option);
	if (option == 0)
	{
		printf("We will generate the primary key for you.\n");
		c = 0;
	}
	else
		c = 1;
	if (get_next_line(fileno(file_ptr), &line))
	{
		list = ft_strsplit(line, ',');
		while (list[c])
		{
			add_column(t, 's', list[c]);
			c++;
		}
	}
	r = 0;
	while (get_next_line(fileno(file_ptr), &line))
	{
		printf("Loaded line %s\n", line);
		list = ft_strsplit(line, ',');
		add_record_from_file(t, r, list, option);
		r++;
	}
	//g_row_counter = r;
	fclose(file_ptr);
}

int			main(int ac, char **av)
{
	t_table		t;

	g_row_counter = 0;
	g_col_counter = 0;
	init_table(&t);
	if (ac == 2)
	{
		g_filename = av[1];
		load_from_file(&t);
	}
	else
		g_filename = "ft_db.csv";
	while (1)
		menu(&t);
	return (0);
}
