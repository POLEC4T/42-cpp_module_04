/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 09:23:08 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 10:34:52 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		_materias[i] = nullptr;
	}
}

MateriaSource & MateriaSource::operator=(const MateriaSource& other) {
	if (this != &other) {
		for (int i = 0; i < _nbMaxMaterias; i++) {
			if (_materias[i] != nullptr)
				delete _materias[i];
			_materias[i] = other._materias[i];
		}
	}
	return (*this);
}

MateriaSource::MateriaSource(const MateriaSource& copy) {
	for (int i = 0; i < _nbMaxMaterias; i++)
		_materias[i] = copy._materias[i];
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i] != nullptr)
			delete _materias[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i] == nullptr) {
			_materias[i] = m;
			return ;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i] != nullptr) {
			if (_materias[i]->getType() == type)
				return (_materias[i]->clone());
		}
	}
	return (0);
}
