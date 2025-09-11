/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 08:40:00 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/08 11:42:11 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

void Character::_initCharacter() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		_materias[i] = 0;
	}
	for (int i = 0; i < _nbMaxUnequiped; i++) {
		_unequiped[i] = 0;
	}
}

void Character::_deleteAll() {
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (_materias[i])
			delete _materias[i];
	}
	for (int i = 0; i < _nbMaxUnequiped; i++) {
		if (_unequiped[i])
			delete _unequiped[i];
	}
}

void Character::copyAll(const Character &c) {
	_name = c._name;
	for (int i = 0; i < _nbMaxMaterias; i++) {
		if (c._materias[i])
			_materias[i] = c._materias[i]->clone();
		else
			_materias[i] = 0;
	}
	for (int i = 0; i < _nbMaxUnequiped; i++) {
		if (c._unequiped[i])
			_unequiped[i] = c._unequiped[i]->clone();
		else
			_unequiped[i] = 0;
	}
}

Character::Character() {
	_name = "Unknown character";
	_initCharacter();
}

Character::~Character() {
	_deleteAll();
}

Character& Character::operator=(const Character& other) {
	if (this != &other) {
		_deleteAll();
		copyAll(other);
	}
	return (*this);
}

Character::Character (const Character& copy) {
	copyAll(copy);
}


Character::Character(std::string name) {
	_initCharacter();
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
	for (int i = 0; i < _nbMaxUnequiped; i++) {
		if (_unequiped[i] == 0) {
			_unequiped[i] = _materias[idx];
			_materias[idx] = 0;
			return ;
		}
	}
	std::cout << "Cannot unequip: Unequiped storage full, materia will be lost" << std::endl;
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
