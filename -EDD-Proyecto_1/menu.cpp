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
#include "transaction.hpp"
#include "assets.hpp"
#include "circular_double_linked_list.hpp"

using namespace std;
Matrix matrix;
Random rando;
List transactionList;
int id_num = 1;
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
        sleep(2);
        mainMenu();
    }
    else if((aux -> getUser() ->getUser()).compare(user) == 0 && (aux -> getUser() -> getPassword()).compare(password) == 0 )
    {
        system("clear");
        cout << ">> ******** Bienvenido " << (aux -> getUser() ->getUser()) <<"..."<< endl;
        cout << ">> Redirigiendo al menú..." << endl;
        sleep(2);
        userMenu(aux);
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
        sleep(1);
        mainMenu();
    }
}

void Menu::newUser()
{
    system("clear");
    std::string password, department, company, id;
    string user;
    
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
        sleep(1);
        newUser();
    }
    Tree* tree = new Tree();
    User* newUser = new User(user, password, department, company, tree);
    matrix.add(department,company, user, newUser);
    sleep(1);
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
            case 3:
                departmentAssetsReport();
                break;
            case 4:
                companyAssetsReport();
                break;
            case 5:
                transactionsReport();
                break;
            case 6:
                userAssetsReport();
                break;
            case 8:
                sortedTransactionsReport();
                break;
            case 9:
                mainMenu();
                break;
            default:
                adminMenu();
                break;
        }
    }while(option <= 0 || option > 9);
}

void Menu::userMenu(Node* user)
{
    system("clear");
    int option;
    cout << ">> ********************* "<< user -> getUser() -> getUser() <<" *********************" << endl;
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
                addAsset(user);
                break;
            case 2:
                modifyAsset(user);
                break;
            case 3:
                removeAsset(user);
                break;
            case 4:
                rentAsset(user);
            case 7:
                mainMenu();
                break;
            default:
                cout << ">> Eliga una de las opciones presentadas." << endl;
        }
    }while(option <= 0 || option > 8);
}

void Menu::addAsset(Node* user)
{
    system("clear");
    std::string id, asset, description;
    //char desc[256];
    id = rando.random_string(15);
    int band = 0;
    cout << ">> ********************* "<< user -> getUser() -> getUser() <<" *********************" << endl;
    cout << ">> ******************* Agregar Activo *******************" << endl;
    cout << ">> ******* Nombre del activo: " << endl;
    cout << ">> ";
    cin >> asset;
    cout << ">> ******* Descripción del activo: " << endl;
    cout << ">> ";
    cin >> description;
    cout << "Activo agregado exitosamente." << endl;
    Asset* newAsset = new Asset(id_num, id, asset, description);
    user -> getUser() -> getAVLTree() -> Insert(newAsset, user -> getUser() -> getAVLTree() -> getRoot(), &band);
    id_num++;
    sleep(1);
    userMenu(user);
}

void Menu::removeAsset(Node* user)
{
    TreeNode* aux;
    int band = 0;
    system("clear");
    int opcion;
    cout << ">> ********************* "<< user -> getUser() -> getUser() <<" *********************" << endl;
    cout << ">> ************************* Eliminar Activo **************************" << endl;
    user -> getUser() -> getAVLTree() -> Preorder(user -> getUser() -> getAVLTree() -> getRoot());
    cout << ">> Elija cuál activo eliminar (ID): ";
    cin >> opcion;
    cout << ">> Eliminando activo..." << endl;
    sleep(1);
    aux = user -> getUser() -> getAVLTree() -> searchAssetIdNum(user -> getUser() -> getAVLTree() -> getRoot(), opcion); // Node found by ID.
    system("clear");
    cout << ">> ******************* "<< user -> getUser() -> getUser() <<" *******************" << endl;
    cout << ">> *********************** Activo a Eliminar *************************" << endl;
    cout << ">> ****** Nombre: " << aux ->getAsset()->getName() << endl;
    cout << ">> ****** ID: " << aux -> getAsset() -> getIdNum() << endl;
    cout << ">> ****** Descripción " << aux -> getAsset() -> getDescription() << endl;
    user -> getUser() -> getAVLTree() -> Remove(user -> getUser() ->getAVLTree() -> getRoot(), NULL, &band, aux -> getAsset() -> getId());
    cout << ">> Activo eliminado exitosamente. Regresando al menú..." << endl;
    sleep(1);
    userMenu(user);
}

void Menu::modifyAsset(Node *user)
{
    TreeNode* nodeFound;
    std::string newDescription, newName;
    system("clear");
    int opcion;
    cout << ">> ************************ "<< user -> getUser() -> getUser() <<" ************************" << endl;
    cout << ">> ****************************** Modificar Activo ********************************" << endl;
    user -> getUser() -> getAVLTree() -> Preorder(user -> getUser() -> getAVLTree() -> getRoot());
    cout << ">> Elija cuál activo modificar (ID): ";
    cin >> opcion;
    sleep(2);
    nodeFound = user -> getUser() -> getAVLTree() -> searchAssetIdNum(user -> getUser() -> getAVLTree() -> getRoot(), opcion); // Node found by ID.
    system("clear");
    cout << ">> ************************ "<< user -> getUser() -> getUser() <<" ************************" << endl;
    cout << ">> ***************************** Activo a Modificar *******************************" << endl;
    cout << ">> ****** Nombre: " << nodeFound ->getAsset()->getName() << endl;
    cout << ">> ****** ID: " << nodeFound -> getAsset() -> getIdNum() << endl;
    cout << ">> ****** Descripción " << nodeFound -> getAsset() -> getDescription() << endl;
    
    cout << ">> Ingrese el nuevo nombre del activo: " << endl;
    cout << ">> ";
    cin >> newName;
    cout << ">> Ingrese la nueva descripción del activo: " << endl;
    cout << ">> ";
    cin >> newDescription;
    nodeFound -> getAsset() -> setName(newName);
    nodeFound -> getAsset() -> setDescription(newDescription);
    cout << ">> Guardando cambios..." << endl;
    sleep(2);
    
    system("clear");
    cout << ">> ************************ "<< user -> getUser() -> getUser() <<" ************************" << endl;
    cout << ">> ***************************** Activo a Modificado ******************************" << endl;
    cout << ">> ****** Nombre: " << nodeFound ->getAsset()->getName() << endl;
    cout << ">> ****** ID: " << nodeFound -> getAsset() -> getIdNum() << endl;
    cout << ">> ****** Descripción: " << nodeFound -> getAsset() -> getDescription() << endl;
    sleep(2);
    userMenu(user);
}

void Menu::userAssetsReport()
{
    Node* aux;
    
    std::string user, company, department;
    system("clear");
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ******************* Reporte Activos Usuario *******************" << endl;
    cout << ">> ****** Usuario:" << endl;
    cout <<">> ";
    cin >> user;
    cout << ">> ****** Departamento:" << endl;
    cout <<">> ";
    cin >> department;
    cout << ">> ****** Empresa:" << endl;
    cout <<">> ";
    cin >> company;
    aux = matrix.SearchValue(department, company);
    if(aux != NULL)
    {
        cout << ">> Verificando usuario..." << endl;
        sleep(2);
        system("clear");
        cout << ">> ************************ Administrador ************************" << endl;
        cout << ">> ******************* Reporte Activos"<< aux -> getUser() -> getUser() <<"*******************" << endl;
        aux -> getUser() -> getAVLTree() -> Preorder(aux -> getUser() -> getAVLTree() -> getRoot());
        cout << ">> Se ha generado la grafica de los activos del usuario. Redirigiendolo al menu..." << endl;
        sleep(4);
        aux -> getUser() -> getAVLTree() -> graphAVL(aux -> getUser() -> getUser());
        adminMenu();
    }
    else
    {
        cout << ">> El usuario no fue encontrado. Verifique sus datos..." << endl;
        sleep(2);
        adminMenu();
    }
}

void Menu::departmentAssetsReport()
{
    system("clear");
    std::string department;
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ************** Reporte Activos por Departamento ***************" << endl;
    cout << ">> Departamento: " << endl;
    cout << ">> ";
    cin >> department;
    matrix.SearchXAssets(department);
    sleep(3);
    adminMenu();
}

void Menu::companyAssetsReport()
{
    system("clear");
    std::string company;
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ***************** Reporte Activos por Empresa *****************" << endl;
    cout << ">> Empresa: " << endl;
    cout << ">> ";
    cin >> company;
    matrix.SearchYAssets(company);
    sleep(3);
    adminMenu();
}

void Menu::rentAsset(Node* user)
{
    Node* aux = nullptr;
    TreeNode* root = nullptr, *assetFound = nullptr;
    system("clear");
    int option;
    std::string username,asset_id,id,time_rented,department,company,date,name;
    cout << ">> ********************** "<< user -> getUser() -> getUser() <<" **********************" << endl;
    cout << ">> ******************** Renta de Activos (Catálogo) **********************" << endl;
    matrix.searchAllAssets(user -> getUser() -> getUser()); // Shows all assets, except from logged user.
    cout << ">> Ingrese el nombre de usuario del cual desea rentar el activo: " << endl;
    cout << ">> ";
    cin >> username;
    aux = matrix.SearchUser(username); // returns user found by username.
    cout << ">> Ingrese cuál activo rentar (ID): " << endl;
    cout << ">> ";
    cin >> option;
    cout << ">> Ingresar días por rentar: " << endl;
    cout << ">> ";
    cin >> time_rented;
    date = "12/06/2020";
    
    // Getting data for transaction.
    
    root = aux -> getUser() -> getAVLTree() -> getRoot(); // root from user's tree.
    assetFound = aux -> getUser() -> getAVLTree() -> searchAssetIdNum(root, option);
    assetFound -> getAsset() -> rented = true;
    company = aux -> getUser() -> getCompany();
    department = aux -> getUser() -> getDepartment();
    id = rando.random_string(15);
    asset_id = assetFound -> getAsset() -> getId();
    name = assetFound -> getAsset() ->getName();
    
    Transaction* transaction = new Transaction(id,asset_id,user -> getUser(),date,time_rented,department,company,name );
    transactionList.InsertSorted(transaction);
    
    
    
    cout <<">> Activo rentado con exito..." << endl;
    sleep(1);
    userMenu(user);
    
}

void Menu::transactionsReport()
{
    system("clear");
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ***************** Reporte Transacciones *****************" << endl;
    transactionList.Display();
    transactionList.graphAsc();
    cout << ">> Se ha generado el reporte de transacciones... " << endl;
    sleep(3);
    adminMenu();
}

void Menu::sortedTransactionsReport()
{
    int option;
    system("clear");
    cout << ">> ************************ Administrador ************************" << endl;
    cout << ">> ***************** Reporte Transacciones *****************" << endl;
    cout << ">> ******* 1. Orden ascendente" << endl;
    cout << ">> ******* 2. Orden descendente" << endl;
    cout << ">> ******* 3. Regresar" << endl;

    cin >> option;
    do{
        switch(option)
        {
            case 1:
                cout << ">> Se ha generado el reporte en orden ascendente..." << endl;
                transactionList.graphAsc();
                sleep(2);
                adminMenu();
                break;
            case 2:
                cout << ">> Se ha generado el reporte en orden descendente..." << endl;
                transactionList.graphDesc();
                sleep(2);
                adminMenu();
                break;
            case 3:
                adminMenu();
                break;
            default:
                cout << ">> Eliga una de las opciones presentadas." << endl;
        }
    }while(option <= 0 || option > 3);
}
