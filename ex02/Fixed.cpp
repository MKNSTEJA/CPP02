/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmummadi <kmummadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/23 23:52:16 by kmummadi          #+#    #+#             */
/*   Updated: 2025/05/26 17:24:43 by kmummadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <cstdint>

// Default constructor
Fixed::Fixed() : _rawBits(0) {
  // std::cout << "Default constructor called\n";
}

Fixed::Fixed(const int input) {
  // std::cout << "Int constructor called\n";
  _rawBits = input << _fractionalBits;
}

Fixed::Fixed(const float input) {
  // std::cout << "Float constructor called\n";
  _rawBits = static_cast<int>(round(input * (1 << _fractionalBits)));
}

// Copy constructor
Fixed::Fixed(const Fixed &other) : _rawBits(other.getRawBits()) {
  // std::cout << "Copy constructor called\n";
}

// Copy assignment operator
Fixed &Fixed::operator=(const Fixed &other) {
  // std::cout << "Copy assignment operator called\n";
  if (this != &other)
    this->_rawBits = other.getRawBits();

  return (*this);
}

// Destructor
Fixed::~Fixed() {
  // std::cout << "Destructor called\n";
}

// Getter function
int Fixed::getRawBits() const { return (_rawBits); }

// Setter function
void Fixed::setRawBits(int const raw) { this->_rawBits = raw; }

// Helper functions
float Fixed::toFloat() const {
  return (static_cast<float>(_rawBits) / (1 << _fractionalBits));
}

int Fixed::toInt() const { return (_rawBits >> _fractionalBits); }

// Overload comparision operators
bool Fixed::operator<(const Fixed &num) {
  return (this->_rawBits < num.getRawBits());
}

bool Fixed::operator>(const Fixed &num) {
  return (this->_rawBits > num.getRawBits());
}

bool Fixed::operator<=(const Fixed &num) {
  return (this->_rawBits <= num.getRawBits());
}

bool Fixed::operator>=(const Fixed &num) {
  return (this->_rawBits >= num.getRawBits());
}

bool Fixed::operator!=(const Fixed &num) {
  return (this->_rawBits != num.getRawBits());
}

bool Fixed::operator==(const Fixed &num) {
  return (this->_rawBits == num.getRawBits());
}

// Overload arithemetic operators
Fixed Fixed::operator+(const Fixed &num) const {
  Fixed result;

  result.setRawBits(this->_rawBits + num.getRawBits());
  return (result);
}

Fixed Fixed::operator-(const Fixed &num) const {
  Fixed result;

  result.setRawBits(this->_rawBits - num.getRawBits());
  return (result);
}

Fixed Fixed::operator/(const Fixed &num) const {
  Fixed result;
  int64_t res;

  res = (static_cast<int64_t>(_rawBits) << _fractionalBits) / num.getRawBits();
  result.setRawBits(static_cast<int>(res));
  return (result);
}

Fixed Fixed::operator*(const Fixed &num) const {
  Fixed result;

  int64_t res = static_cast<int64_t>(_rawBits) * num.getRawBits();
  result.setRawBits(static_cast<int>(res >> _fractionalBits));
  return (result);
}

// Pre increment
Fixed Fixed::operator++() {
  this->_rawBits += this->_eps;
  return (*this);
}

// Post increment
Fixed Fixed::operator++(int) {
  Fixed old(*this);
  ++(*this);

  return (old);
}

// Pre decrement
Fixed Fixed::operator--() {
  _rawBits -= _eps;
  return (*this);
}

// Post decrement
Fixed Fixed::operator--(int) {
  Fixed old(*this);
  --(*this);

  return (old);
}

// Min max functions
Fixed &Fixed::min(Fixed &num1, Fixed &num2) {
  if (num1.getRawBits() < num2.getRawBits())
    return (num1);
  return (num2);
}

const Fixed &Fixed::min(const Fixed &num1, const Fixed &num2) {
  if (num1.getRawBits() < num2.getRawBits())
    return (num1);
  return (num2);
}

Fixed &Fixed::max(Fixed &num1, Fixed &num2) {
  if (num1.getRawBits() > num2.getRawBits())
    return (num1);
  return (num2);
}

const Fixed &Fixed::max(const Fixed &num1, const Fixed &num2) {
  if (num1.getRawBits() > num2.getRawBits())
    return (num1);
  return (num2);
}

std::ostream &operator<<(std::ostream &os, const Fixed &num) {
  os << num.toFloat();
  return os;
}
