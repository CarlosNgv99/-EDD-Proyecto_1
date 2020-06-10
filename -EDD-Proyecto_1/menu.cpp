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
void Menu::mainMenu()
{
    system("clear");
    int answer;
    cout << ">> ************************ Renta de Activos ************************" << endl;
    cout << ">> ******* 1. Iniciar Sesión" << endl;
    cout << ">> ******* 2. Administrador" << endl;
    cout << ">> ******* 3. Salir" << endl;
    cout << ">> ";
    cin >> answer;
    do{
        switch(answer)
        {
            case 1:
                signIn();
                break;
            case 2:
                signInAdmin();
                break;
            case 3:
                system("exit");
                break;
            default:
                cout << ">> Eliga una de las opciones presentadas." << endl;
        }
    }while(answer <= 0 || answer > 4);
}

void Menu::signIn()
{
    Node* aux;
    system("clear");
    std::string user, password, department, company;
    cout << ">> ************************ Inicio de Sesión ************************" << endl;

    cout << ">> ******* Usuario: " << endl;
    cout << ">> ";
    cin >> user;
    cout << ">> ******* Contraseña: " << endl;
    cout << ">> ";
    cin >> password;
    cout << ">> ******* Departamento: " << endl;
    cout << ">> ";
    cin >> department;
    cout << ">> ******* Empresa: " << endl;
    cout << ">> ";
    cin >> company;
    aux = matrix.SearchValue(department, company);
    
    if(aux == NULL)
    {
        cout << ">> El usuario ingresado no fue encontrado." << endl;
        cout << ">> Por favor, verifique sus datos..." << endl;
        sleep(3);
        mainMenu();
    }
    else if((aux -> getUser() ->getUser()).compare(user) == 0 && (aux -> getUser() -> getPassword()).compare(password) == 0 )
    {
        cout << ">> Bienvenido " << (aux -> getUser() ->getUser()) <<"..."<< endl;
        cout << ">> Redirigiendo al menú..." << endl;
        sleep(2);
        userMenu((aux -> getUser() ->getUser()));
    }
    else
    {
        cout << ">> El usuario ingresado no fue encontrado." << endl;
        cout << ">> Por favor, verifique sus datos..." << endl;
        sleep(2);
        mainMenu();
    }
}

void Menu::signInAdmin()
{
    system("clear");
    std::string user, password;
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ***** Usuario: " << endl;
    cout << ">> ";
    cin >> user;
    cout << ">> ***** Contraseña: " << endl;
    cout << ">> ";
    cin >> password;
    
    if(user.compare("admin") == 0 || password.compare("admin") == 0){
        adminMenu();
    }
    else
    {
        cout << ">> Usuario o contraseña incorrecta." << endl;
        cout << ">> Por favor, verifique sus datos..." << endl;
        sleep(2);
        mainMenu();
    }
}

void Menu::newUser()
{
    system("clear");
    std::string password, department, company, id;
    string user;
    id = rando.random_string(15);
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ******* Usuario: " << endl;
    cout << ">> ";
    cin >> user;
    cout << ">> ******* Contraseña: " << endl;
    cout << ">> ";
    cin >> password;
    cout << ">> ******* Departament: " << endl;
    cout << ">> ";
    cin >> department;
    cout << ">> ******* Empresa: " << endl;
    cout << ">> ";
    cin >> company;
    cout << ">> Usuario creado exitosamente..." << endl;
    if(password == "" || user == "" || department == ""|| company == "")
    {
        cout << "<< Ingrese datos válidos para el registro..." << endl;
        sleep(2);
        newUser();
    }
    User* newUser = new User(id, user, password, department, company);
    matrix.add(department,company, user, newUser);
    sleep(2);
    adminMenu();
}

void Menu::adminMenu()
{
    system("clear");
    int option;
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ******* 1. Registrar Usuario" << endl;
    cout << ">> ******* 2. Reporte Matriz Dispersa" << endl;
    cout << ">> ******* 3. Reporte Activos Disponibles de un Departamento" << endl;
    cout << ">> ******* 4. Reporte Activos Disponibles de una Empresa" << endl;
    cout << ">> ******* 5. Reporte Transacciones" << endl;
    cout << ">> ******* 6. Reporte Activos de un Usuario" << endl;
    cout << ">> ******* 7. Activos Rentados por un Usuario" << endl;
    cout << ">> ******* 8. Ordenar Transacciones" << endl;
    cout << ">> ******* 9. Salir" << endl;
    cout << ">> Ingrese una opcion: ";
    cin >> option;
    do{
        switch(option)
        {
            case 1:
                newUser();
                break;
            case 2:
                system("clear");
                cout << ">> ************************ Administrador ************************" << endl;
                cout << ">> ******************* Reporte Matriz Dispersa *******************" << endl;
                cout << ">> Reporte de matriz dispersa generado exitosamente." << endl;
                cout << ">> Regresando al menú..." << endl;
                matrix.getDot();
                sleep(2);
                adminMenu();
                break;
        }
    }while(option <= 0 || option > 9);
}

void Menu::userMenu(std::string username)
{
    system("clear");
    int option;
    cout << ">> ************************ "<< username <<" ************************" << endl;
    cout << ">> ******* 1. Agregar Activo" << endl;
    cout << ">> ******* 2. Modificar Activo" << endl;
    cout << ">> ******* 3. Eliminar Activo" << endl;
    cout << ">> ******* 4. Rentar Activo" << endl;
    cout << ">> ******* 5. Activos Rentados" << endl;
    cout << ">> ******* 6. Mis Activos Rentados" << endl;
    cout << ">> ******* 7. Cerrar Sesión" << endl;
    cout << ">> Ingrese una opcion: ";
    cin >> option;
    do{
        switch(option)
        {
            case 1:
                addAsset(username);
                break;
            case 2:
                break;
            case 7:
                mainMenu();
                break;
            default:
                cout << ">> Eliga una de las opciones presentadas." << endl;
        }
    }while(option <= 0 || option > 8);
}

void Menu::addAsset(std::string username)
{
    string asset, description;
    cout << ">> ************************ "<< username <<" ************************" << endl;
    cout << ">> ************************* Agregar Activo *************************" << endl;
    cout << ">> ******* Nombre del activo: " << endl;
    cout << ">> ";
    cin >> asset;
    cout << ">> ******* Descripción del activo: " << endl;
    cout << ">> ";
    cin >> description;
}
