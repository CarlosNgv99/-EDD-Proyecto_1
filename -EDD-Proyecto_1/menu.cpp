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
#include <unistd.h>
using namespace std;
Matrix matrix;
Random rando;
void Menu::mainLogin()
{
    system("clear");
    int answer;
    cout << ">> ******** Renta de Activos ********" << endl;
    cout << ">> ******** 1.Iniciar Sesión ********" << endl;
    cout << ">> ********* 2.Registrarse **********" << endl;
    cout << ">> ";
    cin >> answer;
    do{
        switch(answer)
        {
            case 1:
                signIn();
                break;
            case 2:
                signUp();
                break;
            default:
                cout << ">> Eliga una de las opciones presentadas." << endl;
        }
    }while(answer <= 0 || answer > 2);
}

void Menu::signIn()
{
    Node* aux;
    system("clear");
    std::string user, password, department, company;
    
    cout << ">> Usuario: " << endl;
    cout << ">> ";
    cin >> user;
    cout << ">> Contraseña: " << endl;
    cout << ">> ";
    cin >> password;
    cout << ">> Departamento: " << endl;
    cout << ">> ";
    cin >> department;
    cout << ">> Empresa: " << endl;
    cout << ">> ";
    cin >> company;
    aux = matrix.SearchValue(department, company);
    if(aux == NULL)
    {
        cout << ">> El usuario ingresado no fue encontrado." << endl;
        cout << ">> Por favor, verifique sus datos..." << endl;
        sleep(3);
        mainLogin();
    }
}

void Menu::signUp()
{
    system("clear");
    std::string password, department, company, id;
    string user;
    id = rando.random_string(15);
    cout << ">> Usuario: " << endl;
    cout << ">> ";
    cin >> user;
    cout << ">> Contraseña: " << endl;
    cout << ">> ";
    cin >> password;
    cout << ">> Departament: " << endl;
    cout << ">> ";
    cin >> department;
    cout << ">> Empresa: " << endl;
    cout << ">> ";
    cin >> company;
    cout << ">> Usuario creado exitosamente." << endl;
    if(password == "" || user == "" || department == ""|| company == "")
    {
        cout << "<< Ingrese datos válidos para el registro..." << endl;
        sleep(2);
        signUp();
    }
    User* newUser = new User(id, user, password, department, company);
    matrix.add(department,company, newUser -> getUser(), newUser);
    matrix.getDot();
}
