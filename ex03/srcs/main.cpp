/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 21:38:04 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/04 17:49:06 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"
#include <iostream>

int main( void ) {
	Point a(-1.25f, -1.25f);
	Point b(2.2f, 2.2f);
	Point c(3.3f, -3.3f);
	Point point1(0.25f, 0.25f);
	Point point2(2.5f, 0.5f);
	Point point3(1.75f, -0.75f);

	std::cout << (bsp(a, b, c, point1) ? "	==> In the triangle" : "	==> Not in the triangle") << std::endl;
	std::cout << (bsp(a, b, c, point2) ? "	==> In the triangle" : "	==> Not in the triangle") << std::endl;
	std::cout << (bsp(a, b, c, point3) ? "	==> In the triangle" : "	==> Not in the triangle") << std::endl;

	return 0;
}