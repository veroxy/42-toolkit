/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/09/27 15:48:40 by qperez            #+#    #+#             */
/*   Updated: 2013/12/29 16:27:17 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unit/s_unit.h>
#include <f_error/m_error.h>

void	D_UNIT_FUNCT(ret_val)
{
	D_UNIT(assert)(M_ERROR(false, "") == false);
	D_UNIT(assert)(M_ERROR(true, "") == true);
	D_UNIT(assert)(M_ERROR(1, "") == 1);
	D_UNIT(assert)(M_ERROR(-1, "") == (size_t)-1);
}

int		main(int argc, char const** argv)
{
	t_unit	unit;

	D_UNIT(init)(&unit);
	D_UNIT(add_context)(&unit, "Method", 0, 0);
	D_UNIT(add_test)(&unit, "Method", ret_val);
	D_UNIT(console_run)(&unit);
	D_UNIT(destroy)(&unit);
	(void)argc;
	(void)argv;
	return (0);
}
