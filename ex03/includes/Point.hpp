/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:27:40 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/09 10:23:34 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {
public:
	Point( void );

	Point(const float x_value, const float y_value);
	Point(const Point& other);

	Point& operator=(const Point& other);
	~Point( void );

	Fixed	getX( void ) const;
	Fixed	getY( void ) const;

private:
	Fixed const	x_;
	Fixed const	y_;
};

std::ostream&	operator<<(std::ostream& os, const Point& Point);

bool	bsp( Point const a, Point const b, Point const c, Point const point);

#endif
