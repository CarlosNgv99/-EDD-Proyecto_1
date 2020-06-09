//
//  main.cpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/5/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include <iostream>
#include "sparse_matrix.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "random_string.hpp"
#include "menu.hpp"
std::string random_string( size_t length );
int main() {
    Menu menu;
    menu.mainLogin();
    return 0;
}

