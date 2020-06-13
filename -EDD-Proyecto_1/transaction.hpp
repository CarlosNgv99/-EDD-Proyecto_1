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
#include "assets.hpp"
class Transaction
{
private:
    Asset* asset;
    int id_num;
    std::string id;
    std::string asste_id;
    User* user;
    std::string date;
    std::string time_rented;
    std::string department;
    std::string company;
    std::string name;


public:
    Transaction(std::string id, std::string asset_id, User* user, std::string date, std::string time_rented, std::string department, std::string company, std::string name,int id_num, Asset* asset)
    {
        this -> asset = asset;
        this -> id_num = id_num;
        this -> name = name;
        this -> id = id;
        this -> asste_id = asset_id;
        this -> user = user;
        this -> date = date;
        this -> time_rented = time_rented;
        this -> department = department;
        this -> company = company;
    }
    Asset* getAsset(){return asset;};
    int getIdNum(){return id_num;};
    std::string getDepartment(){return department;};
    std::string getCompany(){return company;};
    std::string getId(){return id;};
    std::string getRentedid(){return asste_id;};
    User* getUser(){return user;};
    std::string getDate(){return date;};
    std::string getTimeRented(){return time_rented;};
    std::string getName(){return name;};

};

#endif /* transaction_hpp */
