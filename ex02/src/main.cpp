/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:47:44 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/21 03:04:13 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>
#include <sstream>

int main() {
    // The following line will not compile because AAnimal is an abstract class
    // AAnimal cantHappen;

    AAnimal* animal1 = new Dog();
    AAnimal* animal2 = new Cat();

    std::cout << "-----------------------------------\n";

    animal1->makeSound();
    animal2->makeSound();

    std::cout << "-----------------------------------\n";
    delete animal1;
    delete animal2;

    return 0;
}