//
//  transaction.hpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/10/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef transaction_hpp
#define transaction_hpp

#include <stdio.h>
#include <string>
#include "user.hpp"
class Transaction
{
private:
    std::string id;
    std::string rented_id;
    User* user;
    std::string date;
    std::string time_rented;
public:
    Transaction(std::string id, std::string rented_id, User* user, std::string date, std::string time_rented)
    {
        this -> id = id;
        this -> rented_id = rented_id;
        this -> user = user;
        this -> date = date;
        this -> time_rented = time_rented;
    }
    std::string getId(){return id;};
    std::string getRentedid(){return rented_id;};
    User* getUser(){return user;};
    std::string getDate(){return date;};
    std::string getTimeRented(){return time_rented;};
};

#endif /* transaction_hpp */
