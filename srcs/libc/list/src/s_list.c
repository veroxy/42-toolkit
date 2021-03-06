/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_list.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/08/28 20:52:06 by qperez            #+#    #+#             */
/*   Updated: 2013/11/04 09:58:49 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains s_list method>
** < init, print_addr, clear, destroy >
** Copyright (C) <2013>  Quentin Perez <qperez42@gmail.com>
**
** This file is part of 42-toolkit.
**
** 42-toolkit is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdlib.h>
#include <list/s_list.h>
#include <f_string/f_print.h>
#include <f_memory/f_memory.h>

static void	uf_list_funct_destroy(void *data)
{
	(void)data;
}

void		f_list_init(t_list *v_this, void (*uf_funct_destroy)(void *data))
{
	uf_memset(v_this, 0, sizeof(*v_this));
	v_this->f_destroy = uf_list_funct_destroy;
	if (uf_funct_destroy != NULL)
		v_this->f_destroy = uf_funct_destroy;
}

void	f_list_print_addr(const t_list *v_this)
{
	t_list_cell	*current;

	uf_print_str("\033[1;34mBegin\033[0m : ");
	uf_print_addr(v_this->v_begin);
	uf_print_str("\t\t\t\033[1;35mEnd\033[0m : ");
	uf_print_addr(v_this->v_end);
	uf_print_str("\n");
	current = v_this->v_begin;
	while (current != NULL)
	{
		uf_print_addr(current->v_prev);
		if (current->v_prev == NULL)
			uf_print_char('\t');
		uf_print_str("\t<- ");
		uf_print_addr(current);
		uf_print_str(" ->\t");
		uf_print_addr(current->v_next);
		uf_print_str("\n\033[0m");
		current = current->v_next;
	}
}

void		f_list_clear(t_list *v_this)
{
	t_list_cell	*cur;
	t_list_cell	*del;

	cur = v_this->v_begin;
	while (cur != NULL)
	{
		del = cur;
		cur = cur->v_next;
		v_this->f_destroy(del->v_data);
		free(del);
	}
	D_LIST(init)(v_this, v_this->f_destroy);
}

void		f_list_destroy(t_list *v_this)
{
	D_LIST(clear)(v_this);
	v_this->f_destroy = NULL;
}
