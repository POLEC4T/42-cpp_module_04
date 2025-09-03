/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 01:52:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 16:38:05 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "./Animal.hpp"
# include <string>

class Dog : public Animal{
    public:
        Dog();
        virtual ~Dog();
        Dog&operator=(const Dog& other);
        Dog(const Dog& copy);

        virtual void makeSound() const;
};

#endif