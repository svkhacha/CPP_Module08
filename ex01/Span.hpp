#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <exception>

#define RED	    "\33[1;31m"
#define GREEN	"\33[1;32m"
#define YELLOW	"\33[1;33m"
#define CYAN	"\33[1;36m"
#define RESET	"\33[0;m"

typedef std::vector<int>::iterator  It;

class Span
{
    public:
        Span(void);
        Span(unsigned int N);
        Span(const Span& other);
        Span&   operator=(const Span& other);
        ~Span(void);

        void            addNumber(int value);
        void            addNumRange(It begin, It end);
        unsigned int    shortestSpan(void);
        unsigned int    longestSpan(void);

        class FullSpan : public std::exception
        {
            const char* what(void) const throw();
        };

        class NoSpaceInSpan : public std::exception
        {
            const char* what(void) const throw();
        };

        class NoRangeInSpan : public std::exception
        {
            const char* what(void) const throw();
        };

    private:
        std::vector<int>    _v;
};

#endif


