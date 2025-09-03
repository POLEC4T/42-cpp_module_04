/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:18:49 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 06:38:13 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AAnimal.hpp"

AAnimal::AAnimal() : _type("AAnimal") {
    std::cout << _type << " created" << std::endl;
}

AAnimal::~AAnimal() {
    std::cout << "AAnimal destroyed (type=" << _type << ")" << std::endl;
}

AAnimal::AAnimal(const AAnimal &copy) {
    _type = copy._type;
    std::cout << "AAnimal created (copy)" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &other) {
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

std::string AAnimal::getType() const
{
    return (_type);
}