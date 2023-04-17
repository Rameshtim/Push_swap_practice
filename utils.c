/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 14:10:23 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/17 15:49:44 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_perror(char *str)
{
	int	i;

	i = 0;
	write(1, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

int	ft_check_sorted(t_list **stack)
{
	t_list	*head;

	head = *stack;

	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

void	ft_free_stack(t_list **stack)
{
	t_list	*head;
	t_list	*tmp;

	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}