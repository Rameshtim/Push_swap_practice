#include "push_swap.h"

t_list *ft_lstnew(char *thing)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->text = thing;
	new_node->next = NULL;
}
/*
t_list *ft_lstnew(int *thing)
{
	t_list *new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->content = thing;
	new_node->next = NULL;
}

int main()
{
	int	a1 = 5;
	t_list *new_node;
	new_node = ft_lstnew(&a1);
	printf("%d\n", *(new_node->content));
	return (0);
} */

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list *last;

	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		new->next = NULL;
		return ;
	}
	if (lst && new)
	{
		last = *lst;
		while (last->next)
			last = last->next;
		last->next = new;
	}
}

int main()
{
	t_list *list;
	t_list *new;

	list = NULL;
	new = ft_lstnew("From me ");
	ft_lstadd_back(&list, new);
	new = ft_lstnew("Hello");
	ft_lstadd_back(&list, new);

	while (list)
	{
		printf("%s", list->text);
		list = list->next;
	}
	printf("\n");
	return (0);
}
/* int main()
{
	t_list *list;
	t_list *new;

	list = NULL;
	new = ft_lstnew("!");
	ft_lstadd_front(&list, new);
	new = ft_lstnew("Hello");
	ft_lstadd_front(&list, new);

	while (list)
	{
		printf("%s", list->text);
		list = list->next;
	}
	printf("\n");
	return (0);
} */