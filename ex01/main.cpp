/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rjobert <rjobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:08:53 by romainjober       #+#    #+#             */
/*   Updated: 2024/02/20 15:25:46 by rjobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <cassert>

void checker(bool condition)
{
    if (!condition)
         std::cout << RED "FAILURE" RESET << std::endl;
    assert(condition);
    std::cout << GREEN "SUCCESS" RESET << std::endl;
}

int main(void)
{
    Data test_data;
    test_data.name = "testing_set";
    test_data.value = 42;
    std::cout << "Pre-Serializing we have str : " << test_data.name << std::endl;
    std::cout << "Pre-Serializing we have int : " << test_data.value << std::endl;
    std::cout << "it's address is  : " << &test_data << std::endl;
    

    uintptr_t serialized = Serializer::serialize(&test_data);
    std::cout << "After Serializing we have: " << serialized << std::endl;
    
    std::cout << "now we will de-serilaized" << std::endl;
    Data* deserialized = Serializer::deserialize(serialized);
    
    std::cout << "let's verify they are similar" << std::endl;
    
    checker(deserialized == &test_data);

    std::cout << "After deerializing we have: " << deserialized << std::endl;
    std::cout << "Showing it as uintpointer have: " << (uintptr_t) deserialized << std::endl;
    std::cout << "Post-deerializing we have str : " << deserialized->name << std::endl;
    std::cout << "Post-deserializing we have int : " << deserialized->value << std::endl;
}
