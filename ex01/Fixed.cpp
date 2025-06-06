/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:52:16 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/24 13:01:17 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

// Default constructor
Fixed::Fixed() : _rawBits(0) { std::cout << "Default constructor called\n"; }

Fixed::Fixed(const int input) {
  std::cout << "Int constructor called\n";
  _rawBits = input << _fractionalBits;
}

Fixed::Fixed(const float input) {
  std::cout << "Float constructor called\n";
  _rawBits = static_cast<int>(round(input * (1 << _fractionalBits)));
}

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
int Fixed::getRawBits() const { return (_rawBits); }

// Setter function
void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

// Helper functions
float Fixed::toFloat() const {
  return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt() const { return (_rawBits >> _fractionalBits); }

std::ostream &operator<<(std::ostream &os, const Fixed &num) {
  os << num.toFloat();
  return os;
}
