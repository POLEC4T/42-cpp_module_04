/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 07:36:10 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/03 19:34:14 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== Basic Test ===" << std::endl;
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    ICharacter* me = new Character("me");
    AMateria* tmp1;
    AMateria* tmp2;
    tmp1 = src->createMateria("ice");
    me->equip(tmp1);
    tmp2 = src->createMateria("cure");
    me->equip(tmp2);
    ICharacter* bob = new Character("bob");
    me->use(0, *bob);
    me->use(1, *bob);
    delete bob;
    delete me;
    delete src;

    std::cout << "\n=== Full Inventory Test ===" << std::endl;
    IMateriaSource* src2 = new MateriaSource();
    src2->learnMateria(new Ice());
    src2->learnMateria(new Cure());
    ICharacter* alice = new Character("alice");
    
    // Fill inventory (4 slots)
    alice->equip(src2->createMateria("ice"));
    alice->equip(src2->createMateria("cure"));
    alice->equip(src2->createMateria("ice"));
    alice->equip(src2->createMateria("cure"));
    
    // Try to add 5th (should be ignored)
    alice->equip(src2->createMateria("ice"));
    
    ICharacter* target = new Character("target");
    alice->use(0, *target);
    alice->use(1, *target);
    alice->use(2, *target);
    alice->use(3, *target);
    
    delete target;
    delete alice;
    delete src2;

    std::cout << "\n=== Unequip Test ===" << std::endl;
    IMateriaSource* src3 = new MateriaSource();
    src3->learnMateria(new Ice());
    ICharacter* charlie = new Character("charlie");
    AMateria* ice = src3->createMateria("ice");
    charlie->equip(ice);
    charlie->unequip(0); // Should not delete the materia
    delete ice;
    delete charlie;
    delete src3;

    std::cout << "\n=== Copy Test ===" << std::endl;
    IMateriaSource* src4 = new MateriaSource();
    src4->learnMateria(new Ice());
    src4->learnMateria(new Cure());
    
    Character* original = new Character("original");
    original->equip(src4->createMateria("ice"));
    original->equip(src4->createMateria("cure"));
    
    Character* copy = new Character(*original); // Copy constructor
    Character assigned("assigned");
    assigned = *original; // Assignment operator
    
    ICharacter* dummy = new Character("dummy");
    std::cout << "Original: ";
    original->use(0, *dummy);
    std::cout << "Copy: ";
    copy->use(0, *dummy);
    std::cout << "Assigned: ";
    assigned.use(0, *dummy);
    
    delete dummy;
    delete original;
    delete copy;
    delete src4;

    std::cout << "\n=== Edge Cases ===" << std::endl;
    IMateriaSource* src5 = new MateriaSource();
    src5->learnMateria(new Ice());
    
    // Learn more than 4 materias
    src5->learnMateria(new Cure());
    src5->learnMateria(new Ice());
    src5->learnMateria(new Cure());
    src5->learnMateria(new Ice()); // 5th, should be ignored
    
    // Unknown type
    AMateria* unknown = src5->createMateria("fire"); // Should return 0
    if (!unknown)
        std::cout << "Unknown type correctly returned null" << std::endl;
    
    ICharacter* dave = new Character("dave");
    dave->equip(src5->createMateria("ice"));
    
    // Invalid use/unequip
    dave->use(5, *dave); // Out of bounds
    dave->use(-1, *dave); // Negative
    dave->unequip(5); // Out of bounds
    dave->unequip(-1); // Negative
    
    delete dave;
    delete src5;

    std::cout << "\n=== Clone Test ===" << std::endl;
    Ice* ice1 = new Ice();
    AMateria* ice2 = ice1->clone();
    std::cout << "Original type: " << ice1->getType() << std::endl;
    std::cout << "Clone type: " << ice2->getType() << std::endl;
    delete ice1;
    delete ice2;

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}