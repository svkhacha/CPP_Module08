#include "easyfind.hpp"

int main()
{
    std::vector<int>    container;
    container.push_back(11);
    container.push_back(22);
    container.push_back(33);
    container.push_back(44);

    try
    {
        easyfind(container, 33);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    try
    {
        easyfind(container, 67);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

    container.push_back(67);
    try
    {
        easyfind(container, 67);
    }
    catch(std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }

    container.erase(container.begin() + 1);
    try
    {
        easyfind(container, 22);
    }
    catch (std::exception& e)
    {
        std::cout<<e.what()<<std::endl;
    }
    return 0;
}

