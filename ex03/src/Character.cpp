/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:40:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 19:33:24 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::_initMaterias() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		_materias[i] = 0;
	}
}

void Character::_deleteMaterias() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i] != 0)
			delete _materias[i];
	}
}

Character::Character() {
	_name = "Unknown character";
	_initMaterias();
}


Character::~Character() {
	_deleteMaterias();
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_deleteMaterias();
		for (int i = 0; i < _nbMaxMaterias; i++)
			_materias[i] = other._materias[i];
		_name = other._name;
	}
	return (*this);
}

Character::Character (const Character& copy) {
	for (int i = 0; i < _nbMaxMaterias; i++)
		_materias[i] = copy._materias[i];
	_name = copy._name;
}


Character::Character(std::string name) {
	_initMaterias();
	_name = name;
}

std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i] == 0) {
			_materias[i] = m;
			return;
		}
	}
	std::cout << "Cannot equip: Inventory full" << std::endl;
}

void Character::unequip(int idx) {
	if (idx < 0 || idx >= _nbMaxMaterias) {
		std::cout << "Cannot unequip: Index out of range" << std::endl;
		return ;
	}
	_materias[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
	if (idx < 0 || idx >= _nbMaxMaterias) {
		std::cout << "Cannot use: Index out of range" << std::endl;
		return ;
	}
	if (_materias[idx] == 0) {
		std::cout << "Cannot use: No materia equipped" << std::endl;
		return ;
	}

	_materias[idx]->use(target);

}
