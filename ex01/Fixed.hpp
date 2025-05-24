/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:48:09 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/24 12:17:16 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <cmath>
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

  // Getter function
  int getRawBits(void) const;

  // Setter function
  void setRawBits(int const raw);

  // Helper functions
  float toFloat(void) const;
  int toInt(void) const;
};

// Operator overload
std::ostream &operator<<(std::ostream &os, const Fixed &num);
