/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:52:16 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/24 00:05:35 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) { std::cout << "Default constructor called\n"; }

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other.getRawBits()) {
  std::cout << "Copy constructor called\n";
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called\n";
  if (this != &other)
    this->_rawBits = other.getRawBits();

  return (*this);
}

// Destructor
Fixed::~Fixed() { std::cout << "Destructor called\n"; }

// Getter function
int Fixed::getRawBits() const {
  std::cout << "getRawBits member function called\n";
  return (_rawBits);
}

// Setter function
void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }
