/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:13:54 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/27 16:25:43 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <cmath>
#include <iostream>

class	Fixed	{
	public:

	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);
	
	int getRawBits() const;
	void setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	// Overloading comparison operators
	bool	operator>(const Fixed& instance) const;
	bool	operator<(const Fixed& instance) const;
	bool	operator>=(const Fixed& instance) const;
	bool	operator<=(const Fixed& instance) const;
	bool	operator==(const Fixed& instance) const;
	bool	operator!=(const Fixed& instance) const;

	// Overloading arithmetic operators
	Fixed	operator+(const Fixed& instance);
	Fixed	operator-(const Fixed& instance);
	Fixed	operator*(const Fixed& instance);
	Fixed	operator/(const Fixed& instance);

	// Overloading pre-increment/pre-decrement
	Fixed&	operator++();
	Fixed&	operator--();
	
	// Overlaoding post-increment/post-decrement
	Fixed	operator++(int);
	Fixed	operator--(int);
	
	// Comparison functions
	static Fixed&	min(Fixed& n1, Fixed& n2);
	static const Fixed&	min(const Fixed& n1, const Fixed& n2);
	static Fixed&	max(Fixed& n1, Fixed& n2);
	static const Fixed&	max(const Fixed& n1, const Fixed& n2);

	private:

	int _fixedPoint;
	static const int _bits=8;
};

/******************************* Global functions ***************************/

std::ostream& operator<<(std::ostream& stream, const Fixed& instance);

#endif