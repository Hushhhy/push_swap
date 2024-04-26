/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarpent <acarpent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:03:31 by acarpent          #+#    #+#             */
/*   Updated: 2024/04/26 13:33:41 by acarpent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//----------------------------------------------------------------------------*/
//                            INCLUDES                                        */
//----------------------------------------------------------------------------*/

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <limits.h>
// # include <stdio.h>
//----------------------------------------------------------------------------*/
//                            Listes chainees                                 */
//----------------------------------------------------------------------------*/
typedef struct s_stack {
	struct s_stack	*next;
	long long		data;
}			t_stack;

typedef struct s_frst {
	t_stack		*a;
	t_stack		*b;
	char		*jstr;
	char		**spl;
	long long	size_a;
	long long	size_b;
}	t_frst;


void	printlist(t_frst *stack);

//----------------------------------------------------------------------------*/
//                            FONCTIONS SECURITY                              */
//----------------------------------------------------------------------------*/

void		ft_argsec(char **av);
bool		ft_space(char **av);
void		ft_error(char **av);
void		ft_limit(char **split, char *str);
void		*ft_free(char **strs);
t_stack		*ft_lastnode(t_stack *head);
void		null_init(t_frst *stack);
void		ft_lstfree(t_stack **a);
int			is_sorted(t_frst stack);
void		error_free(t_frst *stack);
void		error(void);

//----------------------------------------------------------------------------*/
//                            COMMANDS                                        */
//----------------------------------------------------------------------------*/

void    	ft_rra(t_frst *stack, int boole);
void    	ft_rrb(t_frst *stack, int text);
void    	ft_ra(t_frst *stack, int boole);
void    	ft_rb(t_frst *stack, int text);
void    	ft_sa(t_frst *stack, int boole);
void    	ft_sb(t_frst *stack, int text);
void    	ft_pa(t_frst *stack, int text);
void    	ft_pb(t_frst *stack, int boole);
void    	ft_rrr(t_frst *stack, int text);
void    	ft_rr(t_frst *stack, int text);
void    	ra_rb(t_frst *stack, long long cost_ra, long long cost_rb);
void    	ra_rrb(t_frst *stack, long long cost_ra, long long cost_rrb);
void    	rra_rb(t_frst *stack, long long cost_rra, long long cost_rb);
void    	rra_rrb(t_frst *stack, long long cost_rra, long long const_rrb);

//----------------------------------------------------------------------------*/
//                            Algorythm implementation                        */
//----------------------------------------------------------------------------*/
	
void    	median(t_frst *stack);
void    	cost(t_frst *stack);
void		sort_a(t_frst *stack);
long long  	median_finder(t_frst *stack);
t_stack		*stackcp(t_stack *stack);
t_stack		*ft_lstnew(long long nbr);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **lst, t_stack *new);
void    	quicksort(t_stack *stack, long long lp, long long rp);
long long	partition(t_stack *stack, long long lp, long long rp);
t_stack 	*partition_utils(t_stack *stack, long long lrp);
void 		ft_swap(t_stack *a, t_stack *b);
long long  	cost_ra(t_frst *stack, long long nbr);
long long  	cost_rb(t_frst *stack, long long nbr);
long long  	cost_rra(t_frst *stack, long long nbr);
long long  	cost_rrb(t_frst *stack, long long nbr);
long long  	max_num(long long nbr0, long long nbr1);
void    	operations(t_frst *stack, long long nbr);
void    	ending(t_frst *stack);
long long  	min_a(t_frst *stack);

//----------------------------------------------------------------------------*/
//                            FONCTIONS PARSING                               */
//----------------------------------------------------------------------------*/
char		*ft_strjoin(char const *s1, char const *s2);
size_t		ft_strlen(const char *s);
char		**ft_split(char const *s, char c);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *s, size_t n);
long long	ft_atoll(const char *str);
char		**ft_argvsplit(int ac, char **av);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_itoa(int n);
void		ft_lst(t_stack **head, int nb);
void		ft_putstr_fd(char *s, int fd);
int			ft_lstsize(t_stack *stack);

#endif
