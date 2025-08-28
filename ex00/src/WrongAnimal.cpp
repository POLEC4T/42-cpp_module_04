/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:18:49 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/13 03:16:49 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : _type("WrongAnimal") {
    std::cout << _type << " created" << std::endl;
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed (type=" << _type << ")" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) {
    _type = copy._type;
    std::cout << _type << " created (copy)" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

std::string WrongAnimal::getType() const
{
    return (_type);
}

void WrongAnimal::makeSound() const {
    std::cout << "Some generic wrong animal sound!" << std::endl;
}