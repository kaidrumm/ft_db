#include "../includes/ft_db.h"

void			graceful_exit(t_table *t)
{
	if (t->columns != NULL)
		free(t->columns);
	exit(0);
}

int				id_gen_r(void)
{
	return (++g_row_counter);
}

int				id_gen_c(void)
{
	printf("Column counter is %i\n", g_col_counter);
	return (++g_col_counter);
}

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

int			ask_user_yn(char *question)
{
	char	*response;

	while (1)
	{
		response = ask_user(question);
		if (strcmp(response, "Y") == 0 || strcmp(response, "yes") == 0 || strcmp(response, "y") == 0 || strcmp(response, "Yes") == 0)
			return (1);
		else if (strcmp(response, "N") == 0 || strcmp(response, "no") == 0 || strcmp(response, "n") == 0 || strcmp(response, "No") == 0)
			return (0);
		else
			printf("I'm sorry, please just say a yes or no\n");
	}
	return (-1);
}

void			init_table(t_table *t)
{
	//t->column_ids = (int *)malloc(sizeof(int) * TABLE_SIZE);
	bzero(t->column_ids, sizeof(int) * TABLE_SIZE);
	//t->row_ids = (int *)malloc(sizeof(int) * TABLE_SIZE);
	bzero(t->row_ids, sizeof(int) * TABLE_SIZE);
	t->columns = (t_column *)malloc(sizeof(t_column) * TABLE_SIZE);
}
