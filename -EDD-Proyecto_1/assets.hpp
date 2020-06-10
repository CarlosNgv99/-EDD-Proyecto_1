//
//  assets.hpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/10/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef assets_hpp
#define assets_hpp

#include <stdio.h>
#include <string>
class Asset
{
private:
    int id;
    std::string name;
    std::string description;
public:
    Asset(int id, std::string name, std::string description);
    int getId();
    std::string getDescription();
    std::string getName();
    void setId(int id);
    void setName(std::string name);
    void setDescription(std::string description);
};

#endif /* assets_hpp */
