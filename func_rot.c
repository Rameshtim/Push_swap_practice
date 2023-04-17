/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 16:43:10 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/17 17:20:18 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_rotate(t_list **stack)
{
	t_list *head;
	t_list *tail;

	if (ft_lstsize(stack) < 2)
		return (-1);
	head = *stack;
	//point the first value of stack with head.
	tail = ft_lstlast(head);
	tail->next = head;
	//change tail->next = NULL to first element of stack, so last element becomes second last
	*stack = head->next;
	//now second element will become first element.
	head->next = NULL;
	//first element is pointing to Null which means it has become the last.
	return (0);
}

int	ft_ra(t_list **stack_a)
{
	if (ft_rotate(stack_a) == -1)
		return (-1);
	write (1, "ra", 2);
	return (0);
}

int	ft_rb(t_list **stack_b)
{
	if (ft_rotate(stack_b) == -1)
		return (-1);
	write (1, "rb", 2);
	return (0);
}

int	ft_rr(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(stack_a) < 2 || ft_lstsize(stack_b) < 2)
		return (-1);
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write (1, "rr", 2);
	return (0);
}