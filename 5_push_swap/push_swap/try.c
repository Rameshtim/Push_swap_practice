#include <stdio.h>
#include <stdlib.h>

typedef struct s_node{
	int	data;
	struct s_node *next;
}t_node;

int main()
{
	t_node *head;
	t_node *one; //= NULL;
	t_node *two;// = NULL;
	t_node *three;// = NULL;

	one = malloc(sizeof(t_node));
	two = malloc(sizeof(t_node));
	three = malloc(sizeof(t_node));

	one->data = 10;
	two->data = 20;
	three->data = 30;

	one->next = two;
	two->next = three;
	three->next = NULL;

	head = one;
	int i = 1;

	while (head != NULL)
	{
		printf("Item at position %d is %d\n", i, head->data);
		head = head->next;
		i++;
	}
	free(one);
	free(two);
	free(three);

}