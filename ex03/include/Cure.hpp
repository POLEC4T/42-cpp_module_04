/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:12:33 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 19:03:05 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	public:
		Cure();
		~Cure();
		Cure(const Cure& copy);
		Cure& operator=(const Cure& other);
	
		Cure(std::string const & type);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);
};

#endif