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
    std::string id;
    int id_num;
    std::string name;
    std::string description;
    
public:
    bool rented;
    Asset(int id_num,std::string id, std::string name, std::string description);
    std::string getId();
    int getIdNum();
    void setIdNum(int);
    std::string getDescription();
    std::string getName();
    void setId(std::string id);
    void setName(std::string name);
    void setDescription(std::string description);
};

#endif /* assets_hpp */
