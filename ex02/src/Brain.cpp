/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 02:01:32 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 18:03:06 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Brain.hpp"

Brain::Brain() {
    _currSize = 0;
    std::cout << "Brain created" << std::endl;
}

Brain::~Brain() {
    std::cout << "Brain destroyed" << std::endl;
}

Brain::Brain(const Brain &copy) {
    std::cout << "Brain created (copy)" << std::endl;
    for (int i = 0; i < 100; ++i)
        _ideas[i] = copy._ideas[i];
    _currSize = copy._currSize;
}

Brain& Brain::operator=(const Brain &other) {
    if (this != &other)
    {
        for (int i = 0; i < 100; ++i)
            _ideas[i] = other._ideas[i];
        _currSize = other._currSize;
    }
    std::cout << "Brain assigned" << std::endl;
    return (*this);
}

void Brain::addIdea(const std::string &idea) {
    if (_currSize < 100) {
        _ideas[_currSize] = idea;
        _currSize++;
    } else {
        std::cout << "Brain is full, cannot add more ideas." << std::endl;
    }
}

void Brain::showIdeas() const {
    std::cout << "Brain Ideas:" << std::endl;
    for (unsigned int i = 0; i < _currSize; ++i) {
        std::cout << " - " << _ideas[i] << std::endl;
    }
}



