/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:51:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/15 03:56:45 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        std::cout << "------------Animal test--------------\n";
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }
    {
        std::cout << "\n------------------WrongAnimal test-------------\n";
        const WrongAnimal *test = new WrongAnimal();
        const WrongAnimal *a = new WrongCat();
        std::cout << test->getType() << " " << std::endl;
        std::cout << a->getType() << " " << std::endl;
        test->makeSound();
        a->makeSound();
        delete test;
        delete a;
    }
    return 0;
}