//
//  assets.cpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/10/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "assets.hpp"
#include <string>

Asset::Asset(int id, std::string name, std::string description)
{
    this -> id = id;
    this -> name = name;
    this -> description = description;
}

int Asset::getId()
{
    return id;
}

std::string Asset::getName()
{
    return name;
}

std::string Asset::getDescription()
{
    return description;
}

void Asset::setId(int id)
{
    this -> id = id;
}

void Asset::setName(std::string name)
{
    this -> name = name;
}

void Asset::setDescription(std::string description)
{
    this -> description = description;
}
