#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    int 			*content;
	char			*text;
    struct s_list	*next;
}					t_list;


t_list *ft_lstnew(char *thing);
int	main();
#endif