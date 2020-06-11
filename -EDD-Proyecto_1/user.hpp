//
//  user.hpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/9/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef user_hpp
#define user_hpp

#include <stdio.h>
#include <string>
#include "avl.hpp"
class User
{
private:
    std::string user;
    std::string password;
    std::string department;
    std::string company;
    Tree* avlTree;
public:
    User(std::string user, std::string password, std::string department, std::string company, Tree* newTree)
    {
        this -> user = user;
        this -> password = password;
        this -> department = department;
        this -> company = company;
        this -> avlTree = newTree;
    };
    std::string getUser(){return user;};
    std::string getPassword(){return password;};
    std::string getDepartment(){return department;};
    std::string getCompany(){return company;};
    Tree* getAVLTree(){return avlTree;};
    void setUser(std::string value){user = value;};
    void setPassword(std::string value){password = value;};
    void setDepartment(std::string value){department = value;};
    void setCompany(std::string value){company = value;};
    
};

#endif /* user_hpp */
