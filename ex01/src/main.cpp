/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 02:47:44 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 03:27:27 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Dog.hpp"
#include "../include/Cat.hpp"
#include <iostream>
#include <sstream>

int main() {
    const int N = 4;
    Animal* animals[N];

    std::cout << "\n---creating animals list: ---\n";
    for (int i = 0; i < N; ++i) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n---adding ideas: ---\n";
    for (int i = 0; i < N; ++i) {
        std::ostringstream oss;
        oss << "Idea " << (i + 1);
        animals[i]->addIdea(oss.str());
        animals[i]->showIdeas();
    }

    std::cout << "\n---deleting animals list: ---\n";
    for (int i = 0; i < N; i++)
        delete animals[i];

    std::cout << "\n---deep copy test: ---\n";
    Cat original;
    original.addIdea("Bone");
    Cat copyDog = original;
    original.addIdea("Ball");
    std::cout << "[original]\n";
    original.showIdeas();
    std::cout << "[copy]\n";
    std::cout << "The following ideas were copied: (should not contain Ball)\n";
    copyDog.showIdeas();

    return 0;
}