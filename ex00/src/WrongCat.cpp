/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:28:25 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/13 03:13:05 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat() {
    _type = "WrongCat";
    std::cout << _type << " created" << std::endl;
}

WrongCat::~WrongCat() {
    std::cout << _type << " destroyed" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal::WrongAnimal(copy) {
    std::cout << _type << " created (copy)" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
    if (this != &other) {
        WrongAnimal::operator=(other);
    }
    std::cout << _type << " assigned" << std::endl;
    return (*this);
}

void WrongCat::makeSound() const {
    std::cout << "Meooooow ?? (but nobody hears...)" << std::endl;
}