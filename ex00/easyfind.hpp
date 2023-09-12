#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <exception>
#include <vector>

#define RED	    "\33[1;31m"
#define GREEN	"\33[1;32m"
#define YELLOW	"\33[1;33m"
#define CYAN	"\33[1;36m"
#define RESET	"\33[0;m"

class  NoOccurrenceFound : public std::exception
{
    const char* what() const throw()
    {
        return (RED "EXCEPTION: No occurrence is found" RESET);
    }
};

template <typename T>
void    easyfind(const T& container, int key)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), key);
    if (it == container.end())
    {
        throw NoOccurrenceFound();
    }
    else
    {
        std::cout<<GREEN<<"The integer is found !"<<RESET<<std::endl;
        std::cout<<CYAN<<"Value: "<<RESET;
        std::cout<<YELLOW<<key<<RESET<<std::endl;
        std::cout<<CYAN<<"Index: "<<RESET;
        std::cout<<YELLOW<<it - container.begin()<<RESET<<std::endl;
    }
}

#endif