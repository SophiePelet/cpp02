/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:01:48 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/26 21:05:03 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
// Constructors/destructors, copy constructor and copy assignment operator
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
Fixed::Fixed(const float nb) : _fixedPoint(roundf(nb * 256)) { std::cout << "Float constructor called\n"; }
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

// Getter and setter functions
int	Fixed::getRawBits() const {
	std::cout << "getRawBits member function called\n";
	return (this->_fixedPoint);
}
void	Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called\n";
	this->_fixedPoint = raw;
}

// Conversion functions
float	Fixed::toFloat(void) const { return ((float)_fixedPoint / 256); }
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

// Overloading comparison operators
bool	Fixed::operator>(const Fixed& instance) const { return (this->getRawBits() > instance.getRawBits()); }
bool	Fixed::operator<(const Fixed& instance) const { return (this->getRawBits() < instance.getRawBits()); }
bool	Fixed::operator>=(const Fixed& instance) const { return (this->getRawBits() >= instance.getRawBits()); }
bool	Fixed::operator<=(const Fixed& instance) const { return (this->getRawBits() <= instance.getRawBits()); }
bool	Fixed::operator==(const Fixed& instance) const { return (this->getRawBits() == instance.getRawBits()); }
bool	Fixed::operator!=(const Fixed& instance) const { return (this->getRawBits() != instance.getRawBits()); }

// Overloading arithmetic operators
Fixed	Fixed::operator+(const Fixed& instance) { return (this->getRawBits() + instance.getRawBits()); }
Fixed	Fixed::operator-(const Fixed& instance) { return (this->getRawBits() - instance.getRawBits()); }
Fixed	Fixed::operator*(const Fixed& instance) { return (this->getRawBits() * instance.getRawBits()); }
Fixed	Fixed::operator/(const Fixed& instance) { return (this->getRawBits() / instance.getRawBits()); }

// Overloading pre-increment/pre-decrement
Fixed&	Fixed::operator++() {
	this->setRawBits(this->getRawBits() + 1);
	return (*this);
}
Fixed&	Fixed::operator--() {
	this->setRawBits(this->getRawBits() - 1);
	return (*this);
}

// Overloading post-increment/post-decrement
Fixed	Fixed::operator++(int) {
	Fixed	temp(*this);
	++(*this);
	return (temp);
}
Fixed	Fixed::operator--(int) {
	Fixed	temp(*this);
	--(*this);
	return (temp);
}

// Comparison functions
Fixed& Fixed::min(Fixed& n1, Fixed& n2) {
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
Fixed& Fixed::max(Fixed& n1, Fixed& n2) {
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}
const Fixed&	Fixed::min(const Fixed& n1,const Fixed& n2) {
	if (n1 < n2)
		return (n1);
	else
		return (n2);
}
const Fixed& Fixed::max(const	Fixed& n1, const Fixed& n2)
{
	if (n1 > n2)
		return (n1);
	else
		return (n2);
}