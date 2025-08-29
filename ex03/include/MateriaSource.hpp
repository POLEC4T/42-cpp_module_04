/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:42:05 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 10:13:39 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        static const int _nbMaxMaterias = 4;
		AMateria *_materias[_nbMaxMaterias];

    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource & operator=(const MateriaSource& other);
        MateriaSource(const MateriaSource& copy);
            
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif