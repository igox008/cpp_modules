/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 22:29:30 by alaassir          #+#    #+#             */
/*   Updated: 2024/06/14 22:47:37 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WrongAnimal_HPP
# define WrongAnimal_HPP

#include <iostream>

class   WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		WrongAnimal(const WrongAnimal &an);
		~WrongAnimal();
		
		WrongAnimal	&operator=(const WrongAnimal &an);
		
		void	makeSound() const;
		std::string 	getType() const;
};

#endif
