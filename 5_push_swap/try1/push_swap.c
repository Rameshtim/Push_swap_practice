/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:23:55 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/28 15:02:42 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_list **stack, int argc, char **argv)
{
	t_list *new;
	char **args;
	int	i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new = ft_lstnew_new(ft_atoi(args[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_stack(stack);
	if (argc == 2)
		ft_free(args);	
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	//t_list *head = *stack_a;
	if (ft_lstsize(*stack_a) == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
	}
	else if (ft_lstsize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_lstsize(*stack_a) <= 5)
		sort_4_five(stack_a, stack_b);
	else
		radix_sort(stack_a, stack_b);
	// while (head)
	// {
	// 	printf("%d\n", head->content);
	// 	head = head->next;
	// }
}

int main(int argc, char *argv[])
{
	t_list **stack_a;
	t_list **stack_b;

	if (argc < 2)
		return (1);
	ft_check_args(argc, argv);
	//printf("0.");
	stack_a = (t_list **)malloc(sizeof(t_list));
	stack_b = (t_list **)malloc(sizeof(t_list));
	*stack_a = NULL;
	*stack_b = NULL;
	//printf("1.");
	ft_init_stack(stack_a, argc, argv);
	//printf("2.");
	if (ft_check_sorted(stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		return (0);
	}
	//printf("3.");
	sort_stack(stack_a, stack_b);
	// while (*stack_a)
	// {
	// 	printf("%d\n", (*stack_a)->content);
	// 	(*stack_a) = (*stack_a)->next;
	// }
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	
	return (0);
}