//
//  menu.hpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/8/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#ifndef menu_hpp
#define menu_hpp

#include <stdio.h>
#include <string>
#include "sparse_matrix.hpp"
class Menu{
public:
    Menu(){};
    void showMainMenu();
    void mainMenu();
    void signIn();
    void newUser();
    void signInAdmin();
    void adminMenu();
    void transactionsReport();
    void departmentAssetsReport();
    void companyAssetsReport();
    void userMenu(Node*);
    void addAsset(Node*);
    void removeAsset(Node*);
    void modifyAsset(Node*);
    void rentAsset(Node*);
    void assetsRented(Node*);
    void myRentedAssets(Node*);
    void rentedAssets(Node*);
    void userAssetsReport();
    void sortedTransactionsReport();
};

#endif /* menu_hpp */
