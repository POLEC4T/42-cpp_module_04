/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:55:54 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/21 03:06:52 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria() {
    _type = "AMateria";
    std::cout << "AMateria created" << std::endl;
}

AMateria::AMateria(const AMateria &copy) {
    _type = copy._type;

    std::cout << "AMateria created (copy)" << std::endl;
}


AMateria& AMateria::operator=(const AMateria &other) {
    if (this != &other)
        _type = other._type;

    std::cout << "AMateria assigned" << std::endl;
    return (*this);
}
// AMateria::~AMateria();

// AMateria::AMateria(std::string const & type);
// std::string const & AMateria::getType() const;