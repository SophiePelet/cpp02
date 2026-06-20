/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:39:01 by sophie            #+#    #+#             */
/*   Updated: 2026/06/20 15:00:55 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : _fixedPoint(0) { std::cout << "Default constructor called\n"; }
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
