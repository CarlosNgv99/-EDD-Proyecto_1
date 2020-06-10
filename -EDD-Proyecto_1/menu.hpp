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
class Menu{
public:
    Menu(){};
    void showMainMenu();
    void mainMenu();
    void signIn();
    void newUser();
    void signInAdmin();
    void adminMenu();
    void userMenu(std::string);
    void addAsset(std::string);
    void removeAsset(std::string);
    void modifyAsset(std::string);
    void rentAsset(std::string);
    void assetsRented(std::string);
    void myAssets(std::string);
};

#endif /* menu_hpp */
