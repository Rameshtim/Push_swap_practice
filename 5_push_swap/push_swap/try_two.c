#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int	data;
	struct s_node *next;
}t_node;

t_node *sorted_merge(t_node *a, t_node *b);
void	front_back_split(t_node *source, t_node **front_ref, t_node **back_ref);

void	merge_sort(t_node **head_ref)
{
	t_node *head = *head_ref;
	t_node *a;
	t_node *b;

	if (head == NULL || head->next == NULL)
		return ; //if length is 0 or 1.
	
	//split head into "a" & "b"
	front_back_split(head, &a, &b);

	//recursively sort the sublists;
	merge_sort(&a);
	merge_sort(&b);

	*head_ref = sorted_merge(a, b);
}

t_node *sorted_merge(t_node *a, t_node *b)
{
	t_node *result = NULL;

	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	
	if (a->data <= b->data)
	{
		result = a;
		result->next = sorted_merge(a->next, b);
	}
	else
	{
		result = b;
		result->next = sorted_merge(a, b->next);
	}
	return (result);
}

void	front_back_split(t_node *source, t_node **front_ref, t_node **back_ref)
{
	t_node *fast;
	t_node *slow;

	slow = source;
	fast = source->next;

	//fast moves 2 nodes and slow moves 1 node
	while (fast != NULL)
	{
		fast = fast->next;
		if (fast != NULL)
		{
			slow = slow->next;
			fast = fast->next;
		}
	}

	//slow is before the midpoint in the list,
	//so split it in two at that point.
	*front_ref = source;
	*back_ref = slow->next;
	slow->next = NULL;
}

void	push(t_node **head_ref, int new_data)
{
	t_node *new_node = (t_node *)malloc(sizeof(t_node));
	new_node->data = new_data;
	new_node->next = *head_ref;
	*head_ref = new_node;
}

void print_list(t_node *node)
{
	while (node != NULL)
	{
		printf("%d  ", node->data);
		node = node->next;
	}
}

int main(int argc, char *argv[])
{
	t_node *res = NULL;
	t_node *a = NULL;
	
	push(&a,15);
	push(&a,10);
	push(&a,5);
	push(&a,20);
	push(&a,3);
	push(&a,2);

	printf("Unsorted list\n");
	print_list(a);

	merge_sort(&a);
	printf("\nSorted list\n");
	print_list(a);

}
