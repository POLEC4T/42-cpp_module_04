/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 05:28:43 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 10:03:01 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character : public ICharacter {
	private:
		static const int _nbMaxMaterias = 4;
		std::string _name;
		AMateria *_materias[_nbMaxMaterias];
		
		void _initMaterias();
		void _deleteMaterias();

	public:
		Character();
		~Character();
		Character& operator=(const Character& other);
		Character (const Character& copy);

		Character(std::string name);
		virtual std::string const & getName() const;
        
		virtual void equip(AMateria* m);
        virtual void unequip(int idx);
        virtual void use(int idx, ICharacter& target);
};

#endif