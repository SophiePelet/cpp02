/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:08:12 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/27 17:31:47 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const Point) {
    float cross1 = (b.getX() - a.getX()) * (Point.getY() - a.getY()) - (b.getY() - a.getY()) * (Point.getX() - a.getX());
    float cross2 = (Point.getX() - b.getX()) * (Point.getY() - b.getY()) - (Point.getY() - b.getY()) * (Point.getX() - b.getX());
    float cross3 = (a.getX() - Point.getX()) * (Point.getY() - Point.getY()) - (a.getY() - Point.getY()) * (Point.getX() - Point.getX());

    bool has_neg = (cross1 < 0) || (cross2 < 0) || (cross3 < 0);
    bool has_pos = (cross1 > 0) || (cross2 > 0) || (cross3 > 0);
    bool has_zero = (cross1 == 0) || (cross2 == 0) || (cross3 == 0);

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}    
    
