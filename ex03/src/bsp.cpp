/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:08:12 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/27 18:05:07 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, const Point c, Point const Point) {
    Fixed cross1 = (b.getX() - a.getX()) * (Point.getY() - a.getY()) - (b.getY() - a.getY()) * (Point.getX() - a.getX());
    Fixed cross2 = (c.getX() - b.getX()) * (Point.getY() - b.getY()) - (c.getY() - b.getY()) * (Point.getX() - b.getX());
    Fixed cross3 = (a.getX() - c.getX()) * (Point.getY() - c.getY()) - (a.getY() - c.getY()) * (Point.getX() - c.getX());

    bool has_neg = (cross1 < Fixed(0)) || (cross2 < Fixed(0)) || (cross3 < Fixed(0));
    bool has_pos = (cross1 > Fixed(0)) || (cross2 > Fixed(0)) || (cross3 > Fixed(0));
    bool has_zero = (cross1 == Fixed(0)) || (cross2 == Fixed(0)) || (cross3 == Fixed(0));

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}    
    
