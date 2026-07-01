/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:08:12 by sopelet           #+#    #+#             */
/*   Updated: 2026/07/01 14:05:17 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point) {
    Fixed cross1 = (b.getX() - a.getX()) * (point.getY() - a.getY()) - (b.getY() - a.getY()) * (point.getX() - a.getX());
    Fixed cross2 = (c.getX() - b.getX()) * (point.getY() - b.getY()) - (c.getY() - b.getY()) * (point.getX() - b.getX());
    Fixed cross3 = (a.getX() - c.getX()) * (point.getY() - c.getY()) - (a.getY() - c.getY()) * (point.getX() - c.getX());

    bool has_neg = (cross1 < Fixed(0)) || (cross2 < Fixed(0)) || (cross3 < Fixed(0));
    bool has_pos = (cross1 > Fixed(0)) || (cross2 > Fixed(0)) || (cross3 > Fixed(0));
    bool has_zero = (cross1 == Fixed(0)) || (cross2 == Fixed(0)) || (cross3 == Fixed(0));

    if (has_zero)
        return (false);
    return !(has_neg && has_pos);
}    
    
