#include "MutantStack.hpp"

// SUBJECT code
// int main()
// {
//     MutantStack<int> mstack;
//     mstack.push(5);
//     mstack.push(17);
//     std::cout << mstack.top() << std::endl;
//     mstack.pop();
//     std::cout << mstack.size() << std::endl;
//     mstack.push(3);
//     mstack.push(5);
//     mstack.push(737);
//     //[...]
//     mstack.push(0);
//     MutantStack<int>::iterator it = mstack.begin();
//     MutantStack<int>::iterator ite = mstack.end();
//     ++it;
//     --it;
//     while (it != ite)
//     {
//         std::cout << *it << std::endl;
//         ++it;
//     }
//     std::stack<int> s(mstack);
//     return 0;
// }

//TESTS
int main()
{
    MutantStack<std::string> mstack1;
    mstack1.push("Hello");
    mstack1.push("dear");
    mstack1.push("friend");
    mstack1.push("!");
    
    MutantStack<std::string>::iterator  begin = mstack1.begin();
    MutantStack<std::string>::iterator  end = mstack1.end();
    std::cout<<YELLOW<<"Printing all elements of MutantStack<std::string>"<<std::endl;
    std::cout<<"---------------------------------------------------------------"<<RESET<<std::endl;
    while (begin != end)
    {
        std::cout<<CYAN<<*begin<<" "<<RESET;
        ++begin;
    }
    std::cout<<std::endl;
    std::cout<<PINK<<"Size: "<<RESET<<mstack1.size()<<std::endl;
    std::cout<<PINK<<"Empty: "<<RESET<<RED<<(mstack1.empty() ? "true" : "false")<<RESET<<std::endl;
    std::cout<<std::endl;

    long unsigned int size = mstack1.size();
    for (long unsigned int i = 0; i < size; ++i)
        mstack1.pop();
    std::cout<<YELLOW<<"After poping all elements from MutantStack<std::string>"<<std::endl;
    std::cout<<"---------------------------------------------------------------"<<RESET<<std::endl;
    std::cout<<PINK<<"Size: "<<RESET<<mstack1.size()<<std::endl;
    std::cout<<PINK<<"Empty: "<<RESET<<GREEN<<(mstack1.empty() ? "true" : "false")<<RESET<<std::endl;
    return 0;
}