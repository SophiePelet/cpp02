/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:48 by sopelet           #+#    #+#             */
/*   Updated: 2026/07/01 14:14:19 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) { std::cout << "Default constructor called\n"; }
/*
	shifts all the int bits to the left by 8 postions, to convert it to a
	fixed-point configuration
	the last 8 bits will then be decimal
*/
Fixed::Fixed(const int nb) : _fixedPoint(nb << _bits) { std::cout << "Int constructor called\n"; }
/*
	cannot use bitwise shift operators on floating-point numbers in C++
	mutiply by 256 instead
	`roundf` is necessary because int truncation drops the decimal part instead of
	rounding it.
	`* 256` is a "packing" operation, it shifts the fractional part into the int area so they
	aren't lost when save into a standard `int`
*/
Fixed::Fixed(const float nb) : _fixedPoint(roundf(nb * (1 << _bits))) { std::cout << "Float constructor called\n"; }
Fixed::~Fixed() { std::cout << "Destructor called\n"; }

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called\n";
	this->_fixedPoint = other.getRawBits();
}

Fixed &Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called\n";
	if (this != &other)
		this->_fixedPoint = other.getRawBits();
	return (*this);
}

int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (this->_fixedPoint);
}

void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->_fixedPoint = raw;
}

float	Fixed::toFloat(void) const { return ((float)_fixedPoint / (1 << _bits)); }

int		Fixed::toInt(void) const { return (_fixedPoint >> _bits); }

/*
	Overload of the insertion operator (<<):
	Inserts a floating-point representation of the fixed-point number 
	into the output stream object passed as a parameter
	Couldn't be printed without the overload, as the insertion operator can't print objects
*/
std::ostream&	operator<<(std::ostream& stream, const Fixed& instance) {
	stream << instance.toFloat();
	return (stream);
}