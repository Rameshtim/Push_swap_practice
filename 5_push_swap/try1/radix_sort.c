/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:09:16 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/28 15:35:43 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew_new(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->content = value;
	//create a new node with the index -1
	//proper index will be initialized according in index stack
	new->index = -1;
	new->next = NULL;
	return (new);
}

int	find_maxbits(t_list **stack)
{
	t_list	*head;
	int	max;
	int	max_bits;

	head = *stack;
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
			//find and use the biggest integer.
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
		//right shift the max with max_bits and check with 0
		//as long as bitshifting is possible increase max_bits.
	return (max_bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	t_list *head;
	int	i;
	int	j;
	int	size;
	int	max_bits;

	i = 0;//try i == 1, if it saves some moves.
	head = *stack_a;
	size = ft_lstsize(head);
	max_bits = find_maxbits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head = *stack_a;
			if (((head->index >> i) & 1) == 1)
				ft_ra(stack_a);
			else
				ft_pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			ft_pa(stack_a, stack_b);
		i++;
	}
}