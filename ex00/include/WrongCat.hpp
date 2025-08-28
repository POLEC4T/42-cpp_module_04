/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 01:52:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/13 01:54:11 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <string>

class WrongCat: public WrongAnimal {
    public:
        WrongCat();
        WrongCat&operator=(const WrongCat& other);
        WrongCat(const WrongCat& copy);
        virtual ~WrongCat();

        void makeSound() const;
};

#endif