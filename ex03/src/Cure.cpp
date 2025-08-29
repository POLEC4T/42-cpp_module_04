/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:21:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 10:13:17 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Cure.hpp"

Cure::Cure() {
	_type = "cure";
}

Cure::~Cure() {}

Cure::Cure(const Cure& copy) {
	_type = copy._type;
}

Cure& Cure::operator=(const Cure& other) {
	(void)other;
	return (*this);
}

Cure::Cure(std::string const & type) {
	_type = type;
}

AMateria* Cure::clone() const {
	AMateria * cureClone = new Cure(_type);
	return cureClone;
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals "<< target.getName() << "’s wounds *" << std::endl;
}