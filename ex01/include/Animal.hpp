/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 01:52:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 17:05:52 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {
    protected:
        std::string _type;

    public:
        Animal();
        Animal&operator=(const Animal &other);
        Animal(const Animal &other);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
        virtual void addIdea(const std::string& idea);
        virtual void showIdeas() const;

};

#endif