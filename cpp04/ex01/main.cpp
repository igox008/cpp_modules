/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:51:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/25 11:53:13 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    v()
{
    system("leaks Animal");
}

int main()
{
    // atexit(v);
    {
        Animal  *animal[10];
        for (int i = 0;i < 10;i++)
        {
            if (i % 2 == 0)
                animal[i] = new Dog();
            else
                animal[i] = new Cat();
        }
        for (int i = 0;i < 10;i++)
        {
            std::cout << "Animal type : " << animal[i]->getType() << std::endl;
        }
        for (int i = 0;i <10;i++)
            delete animal[i];
    }
    {
        std::cout << "------------Animal test--------------\n";
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
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