/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 03:24:21 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/20 03:24:21 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "ICharacter.hpp"
#include "MateriaSource.hpp"

int main()
{
    // Instantiate Materia source and learn new Materias
    IMateriaSource* materiaSource = new MateriaSource();
    Ice* iceMateria = new Ice();
    Cure* cureMateria = new Cure();
    materiaSource->learnMateria(iceMateria);
    materiaSource->learnMateria(cureMateria);

    // Create a character named "me"
    ICharacter* player = new Character("me");

    // Create and equip Materias
    AMateria* ice = materiaSource->createMateria("ice");
    player->equip(ice);
    AMateria* cure = materiaSource->createMateria("cure");
    player->equip(cure);
    AMateria* fire = materiaSource->createMateria("fire"); // This will be null
    player->equip(fire);

    // Create another character named "bob" and use Materias on "bob"
    ICharacter* bob = new Character("bob");
    player->use(0, *bob);
    player->use(1, *bob);

    // Attempt to use non-existing inventory slots
    player->use(2, *bob);
    player->use(-1, *bob);
    player->use(10, *bob);

    // Deep copy character "Charles" and perform operations
    Character* charles = new Character("Charles");
    AMateria* cure2 = materiaSource->createMateria("cure");
    charles->equip(cure2);
    AMateria* ice2 = materiaSource->createMateria("ice");
    charles->equip(ice2);
    AMateria* earth = materiaSource->createMateria("earth");
    charles->equip(earth);

    Character* charlesCopy = new Character(*charles);

    // Demonstrate deep copy by altering original "Charles"
    charles->unequip(0);
    charlesCopy->unequip(1);

    AMateria* cure3 = materiaSource->createMateria("cure");
    charlesCopy->equip(cure3);
    AMateria* ice3 = materiaSource->createMateria("ice");
    charlesCopy->equip(ice3);

    // Use Materias on "bob"
    charles->use(0, *bob);
    charles->use(1, *bob);
    charles->use(2, *bob);
    charles->use(3, *bob);

    charlesCopy->use(0, *bob);
    charlesCopy->use(1, *bob);
    charlesCopy->use(2, *bob);
    charlesCopy->use(3, *bob);

    // Unequip Materias from "me" and test usage
    player->unequip(-1);
    player->unequip(10);
    player->unequip(3);

    player->use(1, *charles);
    player->unequip(1);
    player->use(1, *charles);

    // Clean up
    delete iceMateria;
    delete cureMateria;
    delete bob;
    delete player;
    delete materiaSource;
    delete charles;
    delete charlesCopy;

    return 0;
}
