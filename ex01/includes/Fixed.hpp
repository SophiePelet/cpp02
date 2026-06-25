/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sopelet <sopelet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 14:13:54 by sopelet           #+#    #+#             */
/*   Updated: 2026/06/25 14:09:05 by sopelet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <iostream>

class	Fixed	{
	public:

	Fixed();
	Fixed(const int nb);
	Fixed(const float nb);
	~Fixed();
	Fixed(const Fixed& other);
	Fixed &operator=(const Fixed& other);
	
	int getRawBits() const;
	void setRawBits(int const raw);

	float	toFloat(void) const;
	int		toInt(void) const;

	private:

	int _fixedPoint;
	static const int _bits=8;
};

/******************************* Global functions ***************************/

std::ostream& operator<<(std::ostream& stream, const Fixed& instance);
