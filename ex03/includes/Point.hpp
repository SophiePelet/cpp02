/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 15:33:31 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/27 18:03:45 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class	Point {
	public:
	
	Point();
	Point(const float n1, const float n2);
	~Point();
	Point(const Point& other);
	Point &operator=(const Point& other);

	const Fixed& 	getX() const;
	const Fixed&	getY() const;
	
	private:
	
	const Fixed	_x;
	const Fixed	_y;
};

bool	bsp(Point const a, Point const b, Point const c, Point const Point);

#endif