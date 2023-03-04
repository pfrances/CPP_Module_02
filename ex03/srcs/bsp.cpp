/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:55:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/04 17:43:57 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	std::cout	<< "bsp:" << std::endl
				<< "	a: " << a << std::endl
				<< "	b: " << b << std::endl
				<< "	c: " << c << std::endl
				<< "	point: " << point << std::endl;

	float ab_x = b.getX().toFloat() - a.getX().toFloat();
	float ab_y = b.getY().toFloat() - a.getY().toFloat();
	float bc_x = c.getX().toFloat() - b.getX().toFloat();
	float bc_y = c.getY().toFloat() - b.getY().toFloat();
	float ca_x = a.getX().toFloat() - c.getX().toFloat();
	float ca_y = a.getY().toFloat() - c.getY().toFloat();
	float ap_x = point.getX().toFloat() - a.getX().toFloat();
	float ap_y = point.getY().toFloat() - a.getY().toFloat();
	float bp_x = point.getX().toFloat() - b.getX().toFloat();
	float bp_y = point.getY().toFloat() - b.getY().toFloat();
	float cp_x = point.getX().toFloat() - c.getX().toFloat();
	float cp_y = point.getY().toFloat() - c.getY().toFloat();

	float pa = ab_x * ap_y - ab_y * ap_x;
	float pb = bc_x * bp_y - bc_y * bp_x;
	float pc = ca_x * cp_y - ca_y * cp_x;

	return (pa > 0 && pb > 0 && pc > 0) || (pa < 0 && pb < 0 && pc < 0);
}
