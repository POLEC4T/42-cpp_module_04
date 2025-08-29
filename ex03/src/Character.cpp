/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miloniemaz <mniemaz@student.42lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:40:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/08/29 10:35:44 by miloniemaz       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::_initMaterias() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		_materias[i] = nullptr;
	}
}

void Character::_deleteMaterias() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i] != nullptr)
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
		if (_materias[i] == nullptr) {
			_materias[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	// todo save the materia left on the floor to
	// delete it later
	_materias[idx] = nullptr;
}

void Character::use(int idx, ICharacter& target) {
	_materias[idx]->use(target);
}
