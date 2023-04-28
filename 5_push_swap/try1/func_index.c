/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 18:24:01 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/27 15:52:48 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *find_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;
	int	flag;

	flag = 0;
	min = NULL;
	head = *stack;
	while (head)
	{
		//-1 is initialized in ft_listnew for every index at begining, but calling function 
		//will chage the index accordingly after each call.
		if ((head->index == -1) && (flag == 0 || head->content < min->content))
		{
			min = head;
			flag = 1;
		}
		head = head->next;
	}
	return (min);
}

void	index_stack(t_list **stack)
{
	t_list	*head;
	int	index;

	index = 0;
	head = find_next_min(stack);
	//this will get the first minimum from the list.
	while (head)
	{
		//first head->index is initialized in ft_listnew with -1
		//here it will be set appropriately.
		head->index = index++;
		//this will sort the number accordingly and put the appropriate
		//index number from this loop.
		head = find_next_min(stack);
	}
}