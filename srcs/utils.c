#include "../include/ft_ls.h"

void flags_error(char *current, int i)
{
	ft_putstr("\x1B[1;31m");
    ft_putstr("ls: illegal option -- ");
	ft_putchar(current[i]);
	ft_putstr("\nusage: ls [-Ralrt] [file ...]\n");
	ft_putstr("\x1B[0m");
}

void ft_pustrless(const char *str)
{
	int i;

	i = 0;
	ft_putstr("\x1B[1;31m");
	while(str[i+1] != '\0')
		ft_putchar(str[i++]);
}

char *get_path(char path[], char *filename)
{
	ft_strcat(path, filename);
	ft_strcat(path, "/");
	ft_pustrless(path);
	ft_putstr(":\n\x1b[0m");
	return(path);
}

t_node *grab_filepath(char path[], t_node *stack, t_node *head)
{
	t_node *lstcursor;

	lstcursor = head;
    while(lstcursor != NULL)
	{
		lstcursor->path = malloc(strlen(path) + strlen(lstcursor->name) + 1);
        ft_strcpy(lstcursor->path, path);
        ft_strcat(lstcursor->path, lstcursor->name);
		stat(lstcursor->path, &lstcursor->st);
		lstcursor = lstcursor->next;
	}
	return (head);
}

void pop(t_node **head)
{
    if (*head != NULL) 
    {
        t_node *node = *head;
		free(node->name);
        *head = (*head)->next;
        free(node);
    }
}