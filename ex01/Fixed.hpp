/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:48:09 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/24 00:24:23 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>

class Fixed {
private:
  int _rawBits;
  static const int _fractionalBits = 8;

public:
  // Constructor
  Fixed();
  Fixed(const int input);
  Fixed(const float input);

  // Copy Constructor
  Fixed(const Fixed &other);

  // Copy assignment operator overload
  Fixed &operator=(const Fixed &other);

  // Destructor
  ~Fixed();

  int getRawBits(void) const;
  void setRawBits(int const raw);
};
