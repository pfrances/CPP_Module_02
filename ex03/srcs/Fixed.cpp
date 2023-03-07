/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:57:59 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/07 15:44:21 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cmath>

const int Fixed::fractionalBits_ = 8;

Fixed::Fixed( void ) : rawValue_(0) {

}

Fixed::Fixed(const int value) : rawValue_(value << fractionalBits_) {

}

Fixed::Fixed(const float value)
{
	int integerPart = static_cast<int>(value);
	float fractionalPart = value - static_cast<float>(integerPart);

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

Fixed::Fixed(const Fixed& other) : rawValue_(other.rawValue_) {

}

Fixed::~Fixed( void ) {

}

int Fixed::getRawBits() const {
	return this->rawValue_;
}

void Fixed::setRawBits(int const raw) {
	this->rawValue_ = raw;
}

float Fixed::toFloat( void ) const {
	return static_cast<float>(this->rawValue_) / (1 << fractionalBits_);
}

int Fixed::toInt( void ) const {
	return this->rawValue_ >> fractionalBits_;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (this != &other) {
		this->rawValue_ = other.rawValue_;
	}
	return *this;
}

Fixed Fixed::operator+(const Fixed& other) const {
	long result = this->toFloat() + other.toFloat();

	return Fixed(static_cast<float>(result));
}

Fixed Fixed::operator-(const Fixed& other) const {
	long result = this->toFloat() - other.toFloat();

	return Fixed(static_cast<float>(result));
}

Fixed Fixed::operator*(const Fixed& other) const {
	long result = this->toFloat() * other.toFloat();

	return Fixed(static_cast<float>(result));
}

Fixed Fixed::operator/(const Fixed& other) const {
	if (other.getRawBits () == 0) {
		std::cerr << "Error - Cannot divide by zero" << std::endl;
		return Fixed(0);
	}
	return Fixed(this->toFloat() / other.toFloat());
}

bool Fixed::operator>(const Fixed& other) const {
	return (this->rawValue_ > other.rawValue_);
}

bool Fixed::operator<(const Fixed& other) const {
	return (this->rawValue_ < other.rawValue_);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (this->rawValue_ >= other.rawValue_);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (this->rawValue_ <= other.rawValue_);
}

bool Fixed::operator==(const Fixed& other) const {
	return (this->rawValue_ == other.rawValue_);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (this->rawValue_ != other.rawValue_);
}

Fixed& Fixed::operator++( void ) {
	(this->rawValue_)++;
	return *this;
}

Fixed& Fixed::operator--( void ) {
	(this->rawValue_)--;
	return *this;
}

Fixed Fixed::operator++( int ) {
	Fixed temp(*this);
	operator++();
	return temp;
}

Fixed Fixed::operator--( int ) {
	Fixed temp(*this);
	operator--();
	return temp;
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b) ? a : b;
}

std::ostream& operator<<(std::ostream& o, Fixed const& rhs) {
	o << rhs.toFloat();
	return o;
}
