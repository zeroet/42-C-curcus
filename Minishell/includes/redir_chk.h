/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_chk.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sejpark <sejpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:01:04 by sejpark           #+#    #+#             */
/*   Updated: 2021/07/06 13:56:55 by djeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDIR_CHK_H
# define REDIR_CHK_H
# include <stdio.h>
# include "../libft/libft.h"
# include "structs.h"

int	redir_chk(char *str);
int redir_err_chk(t_cmd *cmd_list);

#endif
