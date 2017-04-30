#include "../includes/ft_db.h"

char		*ask_user(char *question)
{
	char	buffer[256];
	char	*response;

	response = NULL;
	bzero(buffer, sizeof(buffer));
	ft_putendl(question);
	if (fgets(buffer, sizeof(buffer), stdin))
	{
		response = strdup(buffer);
		response = strsep(&response, "\n");
	}
	else
		ft_error("Problem with fgets\n");
	return (response);
}

void		menu(t_table *t)
{
	char	buf[10];
	int		option;

	ft_putendl("What operation would you like to perform?\n\t[1] Add Column \n\t[2] Add Record\n\t[3] Print Table\n\t[4] Exit");
	option = atoi(fgets(buf, sizeof(buf), stdin));
	if (option == 1)
		add_column_details(t);
	else if (option == 2)
		add_record(t);
	else if (option == 3)
		print_table(t, 1);
	else if (option == 4)
	{
		print_table(t, 4);
		graceful_exit(t);
	}
	else
		ft_putendl("Sorry, that option isn't covered yet\n");
}

// void		save_to_file(t_table *t, FILE *fp, char *filename)
// {
// 	FILE	*output;

// 	output = fopen(g_filename, "w");

	

// }

void		load_from_file(t_table *t)
{
	FILE	*file_ptr;
	char	*line;
	char 	**list;
	int		r;
	int		c;

	if (!(file_ptr = fopen(g_filename, "r+")))
		ft_error("Error opening file\n");
	if (get_next_line(fileno(file_ptr), &line))
	{
		list = ft_strsplit(line, ',');
		c = 0;
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
		add_record_from_file(t, r, list);
		r++;
	}
	fclose(file_ptr);
}

int			main(int ac, char **av)
{
	t_table		t;

	g_id_counter = 41;
	init_table(&t);
	if (ac == 2)
	{
		g_filename = av[1];
		load_from_file(&t);
	}
	else
		g_filename = "ft_db.txt";
	while (1)
		menu(&t);
	return (0);
}
