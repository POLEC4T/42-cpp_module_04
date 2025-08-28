/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 01:52:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/21 02:20:07 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"
# include <string>

class Dog : public AAnimal{
    private:
        Brain *_brain;

    public:
        Dog();
        virtual ~Dog();
        Dog&operator=(const Dog& other);
        Dog(const Dog& copy);

        virtual void makeSound() const;
        void addIdea(const std::string &idea);
        void showIdeas() const;
};

#endif