/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:47:44 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 16:40:37 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include "../include/WrongAnimal.hpp"
#include "../include/WrongCat.hpp"

int main()
{
    const Animal* animal = new Animal();
    const Animal* dog = new Dog();
    const Animal* cat = new Cat();
    std::cout << dog->getType() << " " << std::endl;
    std::cout << cat->getType() << " " << std::endl;
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();
    
    delete(animal);
    delete(cat);
    delete(dog);

    std::cout << "---------Wrongs---------" << std::endl;

    const WrongAnimal* wrongCat = new WrongCat();

    std::cout << "--" << std::endl;
    std::cout << wrongCat->getType() << " " << std::endl;
    wrongCat->makeSound();
    std::cout << "--" << std::endl;


    delete(wrongCat);

    return 0;
}