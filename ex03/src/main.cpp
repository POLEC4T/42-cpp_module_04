/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mniemaz <mniemaz@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 07:36:10 by miloniemaz        #+#    #+#             */
/*   Updated: 2025/09/11 15:51:05 by mniemaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"
#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main()
{
    std::cout << "=== BASICS ===" << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        ICharacter* me = new Character("me");
        
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        
        ICharacter* bob = new Character("bob");
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
    }
    
    std::cout << "\n=== DEEP COPY ===" << std::endl;
    {
        Character* original = new Character("original");
        original->equip(new Ice());
        original->equip(new Cure());
        
        Character* copy = new Character(*original);
        Character assigned("assigned");
        assigned = *original;
        
        ICharacter* target = new Character("target");
        
        std::cout << "Original: ";
        original->use(0, *target);
        std::cout << "Copy: ";
        copy->use(0, *target);
        std::cout << "Assigned: ";
        assigned.use(0, *target);
        
        delete original;
        delete copy;
        delete target;
    }
    
    std::cout << "\n=== UNEQUIP (no leak) ===" << std::endl;
    {
        Character* hero = new Character("hero");
        AMateria* ice = new Ice();
        hero->equip(ice);
        hero->unequip(0);
        delete hero;
    }
    
    std::cout << "\n=== LIMITS ===" << std::endl;
    {
        Character* player = new Character("player");
        
        player->equip(new Ice());
        player->equip(new Cure());
        player->equip(new Ice());
        player->equip(new Cure());
        
        AMateria* extra = new Ice();
        player->equip(extra);
        delete extra;
        
        Character enemy("enemy");
        player->use(-1, enemy);
        player->use(4, enemy);
        player->unequip(-1);
        player->unequip(4);
        
        delete player;
    }
    
    std::cout << "\n=== FIN DES TESTS ===" << std::endl;
    return 0;
}