/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_strcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qperez <qperez42@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/10/06 21:20:02 by qperez            #+#    #+#             */
/*   Updated: 2013/10/06 22:11:20 by qperez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** <This file contains function>
** < uf_strcpy, uf_strncpy, uf_strlcpy >
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

#include <stddef.h>
#include <f_str_tools.h>
#include <f_memory.h>

char	*uf_strcpy(char *dest, const char *src)
{
	char	*tmp;

	tmp = dest;
	while (*src != '\0')
	{
		*dest = *src;
		dest = dest + 1;
		src = src + 1;
	}
	*dest = '\0';
	return (tmp);
}

char	*uf_strncpy(char *dest, const char *src, size_t size)
{
	char	*tmp;

	tmp = dest;
	while (size != 0)
	{
		*tmp = *src;
		if (*src != 0)
			src++;
		tmp++;
		size--;
	}
	return (dest);
}

size_t	uf_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	ret;
	size_t	len;

	ret = uf_str_len(src);
	if (size != 0)
	{
		if (ret >= size)
			len = size - 1;
		else
			len = ret;
		uf_memcpy(dest, src, len);
		dest[len] = '\0';
	}
	return (ret);
}