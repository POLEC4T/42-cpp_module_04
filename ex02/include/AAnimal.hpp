/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 01:52:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/14 04:09:01 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {
    protected:
        std::string _type;

    public:
        AAnimal();
        AAnimal&operator=(const AAnimal &other);
        AAnimal(const AAnimal &other);
        virtual ~AAnimal();

        virtual void makeSound() const;
        virtual std::string getType() const;
        virtual void addIdea(const std::string& idea) = 0;
        virtual void showIdeas() const = 0;

};

#endif