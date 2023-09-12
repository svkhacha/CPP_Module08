#include "Span.hpp"

Span::Span(void) { _v.reserve(0); }
Span::Span(unsigned int N) { _v.reserve(N); }
Span::Span(const Span& other)
{
    this->_v.reserve(other._v.capacity());
    this->_v = other._v;
}

Span&   Span::operator=(const Span& other)
{
    if (this != &other)
    {
        this->_v.clear();
        this->_v.reserve(other._v.capacity());
        this->_v = other._v;
    }
    return *this;
}

Span::~Span(void) { _v.clear(); }

void    Span::addNumber(int value)
{
    if (_v.size() == _v.capacity())
        throw FullSpan();
    else
    {
        _v.push_back(value);
        std::cout<<YELLOW<<value<<RESET;
        std::cout<<GREEN<<" number added to Span !"<<RESET<<std::endl;
    
    }
}

void    Span::addNumRange(It begin, It end)
{
    if (begin > end)
        return ;
    if (static_cast<unsigned int>(std::distance(begin, end)) > (_v.capacity() - _v.size()))
        throw NoSpaceInSpan();
    else
    {
        _v.insert(_v.end(), begin, end);
        std::cout<<YELLOW<<static_cast<unsigned int>(std::distance(begin, end))<<RESET;
        std::cout<<GREEN<<" numbers added to Span !"<<RESET<<std::endl;
    }
}

unsigned int    Span::shortestSpan(void)
{
    if (_v.size() < 2)
    {
        throw NoRangeInSpan();
        return -1;
    }
    std::sort(_v.begin(), _v.end());
    It  start = _v.begin();
    It  end = start + 1;
    unsigned int    shortest = static_cast<unsigned int>(*end - *start);
    for (; end != _v.end() - 1; ++start, ++end)
    {
        if (static_cast<unsigned int>(*end - *start) < shortest)
            shortest = static_cast<unsigned int>(*end - *start);
    }
    std::cout<<CYAN<<"The shortest Span is "<<RESET;
    return shortest;    
}

unsigned int    Span::longestSpan(void)
{
    if (_v.size() < 2)
    {
        throw NoRangeInSpan();
        return -1;
    }
    std::sort(_v.begin(), _v.end());
    It  start = _v.begin();
    It  end = _v.end();
    unsigned int longest = static_cast<unsigned int>(*(end - 1) - *start);
    std::cout<<CYAN<<"The longest Span is "<<RESET;
    return longest;
}

const char* Span::FullSpan::what(void) const throw()
{
    return (RED "EXCEPTION: The Span is full, no space for new number" RESET);
}

const char* Span::NoSpaceInSpan::what(void) const throw()
{
    return (RED "EXCEPTION: No enough space in Span" RESET);
}

const char* Span::NoRangeInSpan::what(void) const throw()
{
    return (RED "EXCEPTION: The range is not found, no enough numbers in Span" RESET);
}