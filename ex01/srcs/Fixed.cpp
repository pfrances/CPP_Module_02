/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/04 21:37:34 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits_ = 8;

Fixed::Fixed( void ) : rawValue_(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << "Int constructor called" << std::endl;

	this->rawValue_ = value << fractionalBits_;
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called" << std::endl;

	int		integerPart = static_cast<int>(value);
	float	fractionalPart = value - static_cast<float>(integerPart);

	if (value < 0 && fractionalPart != 0) {
		integerPart -= 1;
		fractionalPart = 1 + fractionalPart;
	}
	
	int fixedFractionalPart = 0;
	float fraction = 0.5f;
	for (int i = 0; i < fractionalBits_; ++i) {
		if (fractionalPart >= fraction) {
			fixedFractionalPart |= (1 << (fractionalBits_ - i - 1));
			fractionalPart -= fraction;
		}
		fraction /= 2.0f;
		}

	this->rawValue_ = (integerPart << fractionalBits_) | fixedFractionalPart;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;

	*this = other;
}

Fixed::~Fixed( void ) {
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed& other) {
	std::cout << "Assignation operator called" << std::endl;

	if (this != &other) {
		this->rawValue_ = other.getRawBits();
	}
	return *this;
}

int	Fixed::getRawBits( void ) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->rawValue_;
}

void	Fixed::setRawBits(const int raw) {
	std::cout << "setRawBits member function called" << std::endl;
	this->rawValue_ = raw;
}

float	Fixed::toFloat( void ) const {
	return static_cast<float>(this->rawValue_) / (1 << fractionalBits_);
}

int	Fixed::toInt( void ) const {
	return this->rawValue_ >> fractionalBits_;
}

std::ostream&	operator<<(std::ostream& os, const Fixed& fixed) {
	os << fixed.toFloat();
	return os;
}
