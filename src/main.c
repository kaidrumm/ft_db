#include "../includes/ft_db.h"

// static int	id_gen(void)
// {
// 	return (g_id_counter)
// }

static void add_column_details(t_table *t)
{
	char	name[100];
	char	type[2];

	//bzero(name, 100);
	ft_putendl("Please type the column name");
	gets(name);
	ft_putendl("What type of data is this?");
	gets(type);
	add_column(t, type[0], name);
}

static void	user_interact(t_table *t)
{
	char	buf[10];
	int		option;

	ft_putendl("What operation would you like to perform?\n\t[1] Add Column \n\t[2] Add Record");
	option = atoi(gets(buf));
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
