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

class User
{
private:
    std::string id;
    std::string user;
    std::string password;
    std::string department;
    std::string company;
public:
    User(std::string id, std::string user, std::string password, std::string department, std::string company)
    {
        this -> id = id;
        this -> user = user;
        this -> password = password;
        this -> department = department;
        this -> company = company;
    };
    std::string getId(){return id;};
    std::string getUser(){return user;};
    std::string getPassword(){return password;};
    std::string getDepartment(){return department;};
    std::string getCompany(){return company;};
    void setId(std::string value){id = value;};
    void setUser(std::string value){user = value;};
    void setPassword(std::string value){password = value;};
    void setDepartment(std::string value){department = value;};
    void setCompany(std::string value){company = value;};
};

#endif /* user_hpp */
