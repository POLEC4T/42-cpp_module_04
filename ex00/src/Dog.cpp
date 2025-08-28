/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:39:42 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 03:29:59 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << _type << " created" << std::endl;
}

Dog::~Dog() {
    std::cout << _type << " destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

Dog::Dog(const Dog &copy) : Animal::Animal(copy) {
    std::cout << _type << " created (copy)" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Barkkkkk !" << std::endl;
}