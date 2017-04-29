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

	ft_putendl("What operation would you like to perform?\n\t[1] Add Column \n\t[2] Add Record\n\t[3] Print Table");
	option = atoi(fgets(buf, sizeof(buf), stdin));
	if (option == 1)
		add_column_details(t);
	else if (option == 2)
		add_record(t);
	else if (option == 3)
		print_table(t);
	else
		ft_putendl("Sorry, that option isn't covered yet\n");
}

int			main(void)
{
	t_table		t;

	g_id_counter = 41;
	init_table(&t);
	while (1)
		menu(&t);
	return (0);
}
