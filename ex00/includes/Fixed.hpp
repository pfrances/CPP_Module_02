/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pfrances <pfrances@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 21:58:06 by pfrances          #+#    #+#             */
/*   Updated: 2023/03/04 17:20:24 by pfrances         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed {

public:
	Fixed( void );
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed& other);
	~Fixed( void );

	int getRawBits() const;
	void setRawBits(int const raw);

private:
	int rawValue_;
	static const int fractionalBits_;
};


#endif
