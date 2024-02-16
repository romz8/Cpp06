/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romainjobert <romainjobert@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:36:06 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/16 12:58:03 by romainjober      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <cstdlib> // For rand() and srand()
#include <ctime> 

Base* factory_A() { return new A();}
Base* factory_B() { return new B();}
Base* factory_C() { return new C();}

Base* generate(void)
{

    Base* (*factory[3])() = {factory_A, factory_B, factory_C};
    std::string msg[3] = {GREEN "class A", YELLOW "class B", BLUE "class C"};
    
    int rand_n = rand() % 3;

    std::cout << msg[rand_n] << RESET " created in generate function \n";
    return((*factory[rand_n])());
}

void identify(Base* p)
{
    if (!p)
    {
        std::cout << "null pointer, no downcast\n";
        return ;
    }
    std:: cout << "ptr * id : ";
    A* a = dynamic_cast<A*>(p);
    if (a)
        {
            std::cout << GREEN "this is a class A derived class\n" RESET;
            return ;
        }
    B* b = dynamic_cast<B*>(p);
    if (b)
        {
            std::cout << YELLOW "this is a class B derived class\n" RESET;
            return ;
        }
    C* c = dynamic_cast<C*>(p);
    if (c)
        {
            std::cout << BLUE "this is a class C derived class\n" RESET;
            return ;
        }
    std::cerr << "Unknown derived class" << std::endl;    
}

void identify(Base& p)
{
    std:: cout << "\t ref & id  \n";
    try
    {
        A& a = dynamic_cast<A&>(p);
        (void) a;
        std::cout << GREEN "this is a class A derived class\n" RESET;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\t not class A " << e.what() << '\n';
    }
    try
    {
        B& b = dynamic_cast<B&>(p);
        (void) b;
        std::cout << YELLOW "this is a class B derived class\n" RESET;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\t not class B " <<e.what() << '\n';
    }
    try
    {
        C& c = dynamic_cast<C&>(p);    
        (void) c;
        std::cout << BLUE "this is a class C derived class\n" RESET;
    }
    catch(const std::exception& e)
    {
        std::cerr << "\t not class C " <<e.what() << '\n';
    }
}

int main()
{
    for (int i = 0; i < 20; ++i)
    {
        Base* r = generate();
        identify (r);
        identify (*r);
        delete r;
    std::cout << "\n*********** new test ************\n" << std::endl;
    }
}
