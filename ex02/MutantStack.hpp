#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <iterator>
#include <vector>

#define RED	    "\33[1;31m"
#define GREEN	"\33[1;32m"
#define YELLOW	"\33[1;33m"
#define CYAN	"\33[1;36m"
#define PINK	"\33[1;35m"
#define RESET	"\33[0;m"

template <typename T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container>
{
    public:
        MutantStack(void) { }
        MutantStack(const MutantStack& other) { *this = other; }
        MutantStack& operator=(const MutantStack& other)
        {
            if (this != &other)
                this->c = other.c;
            return *this;
        }

        ~MutantStack(void) { }

        typedef typename std::stack<T>::container_type::iterator iterator;
        iterator    begin() { return this->c.begin(); }
        iterator    end() { return this->c.end(); }
};

#endif