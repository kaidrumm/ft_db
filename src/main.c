#include "../includes/ft_db.h"

// static int	id_gen(void)
// {
// 	return (g_id_counter)
// }

static void add_column_details(t_table *t)
{
	char	line[156];
	char	*name;

	bzero(line, sizeof(line));
	ft_putendl("Please type the column name");
	if (fgets(line, sizeof(line), stdin))
	{
		printf("I heard %s %p\n", line, line);
		name = strdup(line);
		printf("It's still %s %p\n", name, name);
		name = strsep(&name, "\n");
		printf("I jsut removed the newline on %s\n", name);
	}
	bzero(line, sizeof(line));
	ft_putendl("What type of data is this?");
	if (fgets(line, sizeof(line), stdin))
	{
		printf("We still have the name %s; data type is %c\n", name, line[0]);
		add_column(t, line[0], name);
	}
	else
		ft_error("Error reading input\n");
}

static void	user_interact(t_table *t)
{
	char	buf[10];
	int		option;

	ft_putendl("What operation would you like to perform?\n\t[1] Add Column \n\t[2] Add Record\n\t[3] Print Table");
	option = atoi(fgets(buf, sizeof(buf), stdin));
	if (option == 1)
		add_column_details(t);
	// else if (option == 2)
	// 	add_row_details(t);
	else if (option == 3)
		print_table(t);
	else
		ft_putendl("Sorry, that option isn't covered yet\n");
}

int			main(void)
{
	t_table		t;

	init_table(&t);
	while (1)
		user_interact(&t);
	return (0);
}
