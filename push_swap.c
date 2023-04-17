/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtimsina <rtimsina@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:23:55 by rtimsina          #+#    #+#             */
/*   Updated: 2023/04/17 15:13:17 by rtimsina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char *argv[])
{
	t_list **head;
	t_list **bottom;

	if (argc < 2)
		return (1);
		//exit(EXIT_FAILURE);
	ft_check_args(argc, argv);
	printf("I got to be printed.");
	return (0);
}