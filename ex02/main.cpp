/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/26 18:50:53 by sophie            #+#    #+#             */
/*   Updated: 2026/06/27 15:23:14 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>
int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	Fixed c(10);
	Fixed d(2);

	std::cout << c + d << std::endl;
	std::cout << c - d << std::endl;
	std::cout << c / d << std::endl;

	std::cout << (c > d) << std::endl;
	std::cout << (c < d) << std::endl;
	std::cout << (c == d) << std::endl;

	std::cout << --c << std::endl;
	std::cout << c-- << std::endl;
	std::cout << c << std::endl;

	std::cout << Fixed::min( c, d ) << std::endl;

	return 0;
}
