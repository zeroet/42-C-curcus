/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seyun <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 11:19:06 by seyun             #+#    #+#             */
/*   Updated: 2021/10/19 22:27:46 by seyun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_3_b(t_dlst **stack_a,t_dlst **stack_b, int len)
{
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	A_to_B(stack_a, stack_b, len);
}

void	ft_rrb_rra(t_dlst **stack_a, t_dlst **stack_b, t_cntb *b)
{
	int rrrb;
	int ra;
	int rb;

	ra = b->ra_cnt;
	rb = b->rb_cnt;
	if (ra >= rb)
	{
		rrrb = rb;
		ra -= rrrb;
		while (rrrb--)
			ft_rrr(stack_a, stack_b);
		while (ra--)
			ft_rra(stack_a);
	}
	else
	{
		rrrb = ra;
		rb -= rrrb;
		while (rrrb--)
			ft_rrr(stack_a, stack_b);
		while (rb--)
			ft_rrb(stack_b);
	}
}

int		except_case_b(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	if (len == 3)
	{
		sort_3_b(stack_a, stack_b, len);
		return (1);
	}
	if (len == 2 && check_ascend(*stack_b, len))
	{
		ft_sb(*stack_b);
		ft_pa(stack_a, stack_b);
		ft_pa(stack_a, stack_b);
		return (1);
	}
	if (check_descend(*stack_b, len))
	{
		while (len--)
			ft_pa(stack_a, stack_b);
		return (1);
	}
	return (0);
}

void	B_to_A(t_dlst **stack_a, t_dlst **stack_b, int len)
{
	t_cntb b;
	int pivot;

	init_cnt_b(&b);
	init_pivot_b(stack_b, len, &b);
	pivot = set_pivot(*stack_b, len);
	if (except_case_b(stack_a, stack_b, len))
		return ;
	while (len--)
	{
		if ((*stack_b)->num < b.small_pivot)
		{
			ft_rb(stack_b);
			(b.rb_cnt)++;
		}
		else if ((*stack_b)->num >= b.small_pivot)
		{
			ft_pa(stack_a, stack_b);
			(b.pa_cnt)++;
			if ((*stack_a)->num < pivot)
			{
				ft_ra(stack_a);
				(b.ra_cnt)++;
			}
		}
	}
	A_to_B(stack_a, stack_b, (b.pa_cnt - b.ra_cnt));
	ft_rrb_rra(stack_a, stack_b, &b);
	A_to_B(stack_a, stack_b, b.ra_cnt);
	B_to_A(stack_a, stack_b, b.rb_cnt);
}
