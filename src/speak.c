/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   speak.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kdrumm <kdrumm@student.42.us>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/05 11:21:22 by kdrumm            #+#    #+#             */
/*   Updated: 2017/05/05 16:06:33 by kdrumm           ###   ########.us       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_db.h"

void		usage(t_table *t)
{
	ft_putstr("\nUsage:\n"
		"./ft_db -h -w -f\n"
		"-h height (in integer range)\n"
		"-w width (in integer range)\n"
		"-f filename to load input from file\n\n"
		"If you do not give height and width dimensions, default is 100\n"
		"./ft_db with no parameters opens a blank spreadsheet, \nwhich will "
		"save as ft_db.csv and overwrite any file by that name.\n\n");
	graceful_exit(t);
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
		if (strcmp(response, "Y") == 0 || strcmp(response, "yes") == 0 \
			|| strcmp(response, "y") == 0 || strcmp(response, "Yes") == 0)
			return (1);
		else if (strcmp(response, "N") == 0 || strcmp(response, "no") == 0 \
			|| strcmp(response, "n") == 0 || strcmp(response, "No") == 0)
			return (0);
		else
			printf("I'm sorry, please just say a yes or no\n");
	}
	return (-1);
}

static int	offer_menu(t_table *t)
{
	char	buf[10];
	int		option;

	ft_putendl("\nWhat operation would you like to perform?\n\t"
		"[1] Add Column \n\t"
		"[2] Add Record\n\t"
		"[3] Update Value\n\t"
		"[4] Delete Record\n\t"
		"[5] Delete Column\n\t"
		"[6] Search by Value\n\t"
		"[7] Print Table\n\t"
		"[8] Save & Exit\n\t"
		"[9] Help\n\t"
		"[10] Flee\n\t");
	option = atoi(fgets(buf, sizeof(buf), stdin));
	if (option == 8)
	{
		print_table(t, 4);
		graceful_exit(t);
	}
	return (option);
}

void		menu(t_table *t)
{
	int		option;

	option = offer_menu(t);
	if (option == 1)
		add_column(t, ask_user("Please type the column name"));
	else if (option == 2)
		add_record(t);
	else if (option == 3)
		update_value(t);
	else if (option == 4)
		delete_record(t);
	else if (option == 5)
		delete_column(t);
	else if (option == 6)
		search_query(t);
	else if (option == 7)
		print_table(t, 1);
	else if (option == 8)
		;
	else if (option == 9)
		usage(t);
	else if (option == 10)
		graceful_exit(t);
	else
		ft_putendl("Sorry, that option isn't covered yet\n");
}
