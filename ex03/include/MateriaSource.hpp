/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 02:42:05 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 19:28:04 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    private:
        static const int _nbMaxLearnedMaterias = 4;
		AMateria *_learnedMaterias[_nbMaxLearnedMaterias];

    public:
        MateriaSource();
        virtual ~MateriaSource();
        MateriaSource & operator=(const MateriaSource& other);
        MateriaSource(const MateriaSource& copy);
            
        virtual void learnMateria(AMateria*);
        virtual AMateria* createMateria(std::string const & type);
};

#endif