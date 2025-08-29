/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:32:58 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 10:08:43 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
#define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;
class AMateria {
    protected:
        std::string _type;

    public:
        AMateria();
        AMateria(const AMateria &copy);
        AMateria& operator=(const AMateria &other);
        virtual ~AMateria();

        AMateria(std::string const & type);
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target) = 0;
};

#endif