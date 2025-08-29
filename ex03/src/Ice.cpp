/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:21:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 08:25:08 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice() {
	_type = "ice";
}

Ice::~Ice() {}

Ice::Ice(const Ice& copy) {
	_type = copy._type;
}

Ice& Ice::operator=(const Ice& other) {
	(void) other;
	return (*this);
}

Ice::Ice(std::string const & type) {
	_type = type;
}

AMateria* Ice::clone() const {
	AMateria * iceClone = new Ice(_type);
	return iceClone;
}

void Ice::use(ICharacter& target) {
	std::cout << "* shoots an ice bolt at "<< target.getName() << " *" << std::endl;
}