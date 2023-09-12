#include "Span.hpp"

int main()
{
    try
    {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        sp.addNumber(8);
    
        std::cout<<sp.shortestSpan()<<std::endl;
        std::cout<<sp.longestSpan()<<std::endl;
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

    try
    {
        Span sp1;
        std::cout<<sp1.shortestSpan()<<std::endl;
        std::cout<<sp1.longestSpan()<<std::endl;
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

    try
    {
        Span sp2;
        std::vector<int> vec;
        vec.push_back(12);
        vec.push_back(22);
        vec.push_back(32);
        vec.push_back(42);
        sp2.addNumRange(vec.begin(), vec.end());
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

     try
    {
        Span sp3(10);
        std::vector<int> vec;
        vec.push_back(12);
        vec.push_back(22);
        vec.push_back(32);
        vec.push_back(42);
        sp3.addNumRange(vec.begin(), vec.end());
        std::cout<<sp3.shortestSpan()<<std::endl;
        std::cout<<sp3.longestSpan()<<std::endl;
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}