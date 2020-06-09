//
//  menu.cpp
//  -EDD-Proyecto_1
//
//  Created by Carlos NG on 6/8/20.
//  Copyright © 2020 Carlos NG. All rights reserved.
//

#include "menu.hpp"
#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdlib>
#include "user.hpp"
#include "random_string.hpp"
#include "sparse_matrix.hpp"
using namespace std;
Matrix matrix;
void Menu::mainLogin()
{
    int answer;
    cout << "******** Renta de Activos ********" << endl;
    cout << "******** 1.Iniciar Sesión ********" << endl;
    cout << "********* 2.Registrarse **********" << endl;
    cout << ">> ";
    cin >> answer;
    do{
        switch(answer)
        {
            case 1:
                signIn();
                break;
            default:
                cout << "Eliga una de las opciones presentadas." << endl;
        }
    }while(answer <= 0 || answer > 2);
}

void Menu::signIn()
{
    system("clear");
    std::string user, password;
    
    cout << "Usuario: " << endl;
    cin >> user;
    cout << "\nContraseña: " << endl;
    cin >> password;
}

void Menu::signUp()
{
    Random rand;
    system("clear");
    std::string user, password, department, company, id;
    id = rand.random_string(15);
    cout << "Usuario: " << endl;
    cin >> user;
    cout << "\nContraseña: " << endl;
    cin >> password;
    cout << "\nDepartament: " << endl;
    cin >> department;
    cout << "\nEmpresa: " << endl;
    cin >> company;
    User* newUser = new User(id, user, password, department, company);
    matrix.add(id,department,company);
    
}
