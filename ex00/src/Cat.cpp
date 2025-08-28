/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:28:25 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 02:30:11 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << _type << " created" << std::endl;
}

Cat::~Cat() {
    std::cout << _type << " destroyed" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy) {
    std::cout << _type << " created (copy)" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meooooow !" << std::endl;
}