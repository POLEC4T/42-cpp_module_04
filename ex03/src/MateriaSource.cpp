/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:23:08 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 19:28:00 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < _nbMaxLearnedMaterias; i++) {
		_learnedMaterias[i] = 0;
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _nbMaxLearnedMaterias; i++) {
			if (_learnedMaterias[i] != 0)
				delete _learnedMaterias[i];
			_learnedMaterias[i] = other._learnedMaterias[i];
		}
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	// learned materias
	for (int i = 0; i < _nbMaxLearnedMaterias; i++)
		_learnedMaterias[i] = copy._learnedMaterias[i];
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _nbMaxLearnedMaterias; i++) {
		if (_learnedMaterias[i] != 0)
			delete _learnedMaterias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < _nbMaxLearnedMaterias; i++) {
		if (_learnedMaterias[i] == 0) {
			_learnedMaterias[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource: cannot learn more materias" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _nbMaxLearnedMaterias; i++) {
		if (_learnedMaterias[i] != 0) {
			if (_learnedMaterias[i]->getType() == type) {
				return (_learnedMaterias[i]->clone());
			}
		}
	}
	std::cout << "MateriaSource: unknown materia type '" << type << "'" << std::endl;
	return (0);
}
