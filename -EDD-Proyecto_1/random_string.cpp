//
//  random_string.cpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/9/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "random_string.hpp"
#include <string>
std::string Random::random_string(size_t length)
{
    auto random_char = []() -> char
    {
        const char charset[] =
        "0123456789"
        "abcdefghijklmnopqrstuvwxyz";
        const size_t max_index = (sizeof(charset) - 1);
        return charset[rand() % max_index];
    };
    std::string str(length,0);
    std::generate_n(str.begin(), length, random_char);
    return str;
}
