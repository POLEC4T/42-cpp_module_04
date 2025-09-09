/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:18:49 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/08 16:55:23 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Animal.hpp"

Animal::Animal() : _type("Animal") {
    std::cout << _type << " created" << std::endl;
}

Animal::~Animal() {
    std::cout << "Animal destroyed (type=" << _type << ")" << std::endl;
}

Animal::Animal(const Animal &copy) {
    _type = copy._type;
    std::cout << "Animal created (copy)" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
    if (this != &other)
    {
        _type = other._type;
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

std::string Animal::getType() const
{
    return (_type);
}

void Animal::makeSound() const {}

void Animal::addIdea(const std::string &idea) { (void) idea; }

void Animal::showIdeas() const {}