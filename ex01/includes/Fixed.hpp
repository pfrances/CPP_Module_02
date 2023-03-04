/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/04 14:49:44 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {
public:
	Fixed( void );
	Fixed(const int num);
	Fixed(const float num);
	Fixed(const Fixed& other);
	~Fixed( void );

	Fixed& operator=(const Fixed& other);

	int getRawBits( void ) const;
	void setRawBits(const int raw);

	float toFloat( void ) const;
	int toInt( void ) const;

private:
	int rawValue_;
	static const int fractionalBits_;

};

std::ostream& operator<<(std::ostream& os, const Fixed& fixed);

#endif
