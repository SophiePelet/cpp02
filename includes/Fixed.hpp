/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sophie <sophie@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 14:33:33 by sophie            #+#    #+#             */
/*   Updated: 2026/06/20 14:55:10 by sophie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Fixed {
	public:

	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);

	int getRawBits() const;
	void setRawBits(int const raw);

	private:

	int _fixedPoint;
	static const int _bits=8;
};
