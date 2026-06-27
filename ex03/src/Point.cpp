/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:46:08 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/27 17:29:07 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

Point::Point() : _x(0), _y(0) {
}
Point::Point(const float n1, const float n2) : _x(n1), _y(n2) {
}
Point::~Point() {
}
Point::Point(const Point& other) : _x(other._x), _y(other._y) {
}
Point &Point::operator=(const Point& other) {
	(void)other;
	return (*this);
}


// Getter function for the point coordinates
const Fixed&	Point::getX() const { return (this->_x); }
const Fixed&	Point::getY() const { return (this->_y); }