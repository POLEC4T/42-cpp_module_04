/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:02:10 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 19:03:01 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {
	public:
		Ice();
		Ice(const Ice &copy);
		Ice& operator=(const Ice &other);
		~Ice();

		Ice(std::string const & type);
        virtual AMateria* clone() const;
        virtual void use(ICharacter& target);

};

#endif