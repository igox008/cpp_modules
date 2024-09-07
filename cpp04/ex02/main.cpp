/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 00:51:16 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/16 05:27:02 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

void    v()
{
    system("leaks AAnimal");
}

int main()
{
    // atexit(v);
    {
        AAnimal  *AAnimal[10];
        for (int i = 0;i < 10;i++)
        {
            if (i % 2 == 0)
                AAnimal[i] = new Dog();
            else
                AAnimal[i] = new Cat();
        }
        for (int i = 0;i < 10;i++)
        {
            std::cout << "AAnimal type : " << AAnimal[i]->getType() << std::endl;
        }
        for (int i = 0;i < 10;i++)
            delete AAnimal[i];
    }
    {
        std::cout << "------------AAnimal test--------------\n";
        // const AAnimal* meta = new AAnimal();
        const AAnimal* j = new Dog();
        const AAnimal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        // meta->makeSound();
        // delete meta;
        delete i;
        delete j;
    }
    return 0;
}