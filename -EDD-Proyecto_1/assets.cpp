//
//  assets.cpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/10/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "assets.hpp"
#include <string>

Asset::Asset(int id_num, std::string id, std::string name, std::string description)
{
    this -> id_num = id_num;
    this -> id = id;
    this -> name = name;
    this -> description = description;
    this -> rented = false; // Not rented yet.
}

std::string Asset::getId()
{
    return id;
}

int Asset::getIdNum()
{
    return id_num;
}

void Asset::setIdNum(int value)
{
    id_num = value;
}

std::string Asset::getName()
{
    return name;
}

std::string Asset::getDescription()
{
    return description;
}

void Asset::setId(std::string id)
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
