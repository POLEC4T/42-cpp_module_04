/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:39:42 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/21 02:24:41 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"

Dog::Dog() {
    _type = "Dog";
    std::cout << _type << " created" << std::endl;
    _brain = new Brain();
}

Dog::~Dog() {
    delete(_brain);
    std::cout << _type << " destroyed" << std::endl;
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        AAnimal::operator=(other);
        delete (_brain);
        _brain = new Brain(*other._brain);
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

Dog::Dog(const Dog &copy) : AAnimal::AAnimal(copy) {
    _brain = new Brain(*copy._brain);
    std::cout << _type << " created (copy)" << std::endl;
}

void Dog::makeSound() const {
    std::cout << "Barkkkkk !" << std::endl;
}

void Dog::addIdea(const std::string &idea) {
    _brain->addIdea(idea);
}

void Dog::showIdeas() const {
    _brain->showIdeas();
}
