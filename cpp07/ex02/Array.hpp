/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alaassir <alaassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 03:29:43 by alaassir          #+#    #+#             */
/*   Updated: 2024/09/02 03:56:37 by alaassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private :
        T *arr;
        unsigned int arr_size;
    public :
        Array()
        {
            arr_size = 0;
            arr = new T[arr_size];
        }
        Array(unsigned int sz)
        {
            arr_size = sz;
            arr = new T[arr_size];
        }
        Array(Array &cpy)
        {
            arr_size = cpy.arr_size;
            arr = NULL;
            *this = cpy;
        }
        ~Array()
        {
            delete [] arr;
        }
        Array &operator=(Array &cpy)
        {
            if (arr != NULL)
                delete [] arr;
            arr_size = cpy.arr_size;
            if (arr_size == 0)
                return *this;
            arr = new T[arr_size];
            for (unsigned int i = 0; i < arr_size;i++)
            {
                arr[i] = cpy.arr[i];
            }
            return *this;
        }

        class OutOfBoundException : public std::exception
        {
            public :
                const char *what() const throw()
                {
                    return ("Index Is Out Of Bounds");
                }  
        };
        T &operator[](unsigned int idx)
        {
            if (idx >= arr_size)
                throw OutOfBoundException();
            return (arr[idx]);
        }

        unsigned int size(void) const
        {
            return (arr_size);
        }
};



#endif
