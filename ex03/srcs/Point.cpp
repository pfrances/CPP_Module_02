/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 15:30:58 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/04 17:47:33 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point( void ) : x_(0), y_(0) {

}

Point::Point( const float x_value, const float y_value ) : x_(x_value), y_(y_value) {

}

Point::Point(const Point& other) : x_(other.x_), y_(other.y_) {

}

Point& Point::operator=(const Point& other) {
	if (this != &other) {
		const_cast<Fixed&>(this->x_) = other.x_;
		const_cast<Fixed&>(this->y_) = other.y_;
	}
	return *this;
}

Point::~Point( void ) {

}

Fixed Point::getX( void ) const {
	return this->x_;
}

Fixed Point::getY( void ) const {
	return this->y_;
}

std::ostream& operator<<(std::ostream& o, Point const& rhs) {
	o << "x=" << rhs.getX().toFloat() << " y=" << rhs.getY().toFloat();
	return o;
}