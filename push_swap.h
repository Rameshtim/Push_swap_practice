#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
    int 			content;
    int             index;
    struct s_list	*next;
}					t_list;

size_t	ft_strlen(const char *s);
int	ft_atoi(const char *nptr);
int	ft_isdigit(int c);
char	**ft_split(char const *s, char c);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstlast(t_list *lst);

void	ft_check_args(int argc, char **av);
int	ft_pa(t_list **stack_a, t_list **stack_b);
int	ft_pb(t_list **stack_a, t_list **stack_b);
int	ft_sa(t_list **stack_a);
int	ft_sb(t_list **stack_b);
int	ft_ss(t_list **stack_a, t_list **stack_b);
int	ft_ra(t_list **stack_a);
int	ft_rb(t_list **stack_b);
int	ft_rr(t_list **stack_a, t_list **stack_b);
int	ft_rra(t_list **stack_a);
int	ft_rrb(t_list **stack_b);
int	ft_rrr(t_list **stack_a, t_list **stack_b);

void	ft_free_stack(t_list **stack);
int	ft_check_sorted(t_list **stack);
void	ft_perror(char *str);

int	main(int argc, char *argv[]);
#endif