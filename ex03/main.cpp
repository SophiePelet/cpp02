/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 17:45:19 by sopelet           #+#    #+#             */
/*   Updated: 2026/07/01 14:29:18 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

int	main(void) {
	Point	a(0.0f, 0.0f);
	Point	b(6.0f, 0.0f);
	Point	c(0.0f, 6.0f);
	Point	point(1.0f, 1.0f);
	//Point	point(6.0f, 6.0f);
	//Point	point(12.0f, 12.0f);

	bool	is_in = bsp(a, b, c, point);
	std::cout << is_in << std::endl;
	
	return (0);
}