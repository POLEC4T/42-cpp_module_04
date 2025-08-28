/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:28:25 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 03:29:06 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Cat.hpp"

Cat::Cat() {
    _type = "Cat";
    std::cout << _type << " created" << std::endl;
    _brain = new Brain();
}

Cat::~Cat() {
    delete(_brain);
    std::cout << _type << " destroyed" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal::Animal(copy) {
    std::cout << _type << " created (copy)" << std::endl;
    _brain = new Brain(*copy._brain);
}

Cat& Cat::operator=(const Cat &other) {
    if (this != &other) {
        Animal::operator=(other);
        delete _brain;
        _brain = new Brain(*other._brain);
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

void Cat::makeSound() const {
    std::cout << "Meooooow !" << std::endl;
}

void Cat::addIdea(const std::string &idea) {
    _brain->addIdea(idea);
}

void Cat::showIdeas() const {
    _brain->showIdeas();
}