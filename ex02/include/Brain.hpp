/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 01:57:37 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 03:04:20 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {
    private:
        unsigned int _currSize;
        std::string _ideas[100];

    public:
        Brain();
        ~Brain();
        Brain(const Brain &copy);
        Brain& operator=(const Brain &other);

        void addIdea(const std::string &idea);
        void showIdeas() const;

};

#endif