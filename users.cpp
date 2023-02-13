#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <chrono>
#include <thread>
#include "users.h"

std::fstream usersFile;

std::vector<Users> Users::getAll() {
    // Returns a vector of all users
    usersFile.open("users.csv", std::ios::in);

    std::string row;

    std::vector<Users> users;

    int rowCount = 0;
    getline(usersFile, row); // ignore header line

    Users user;

    while (getline(usersFile, row) && !row.empty())
    {
        std::stringstream mystream(row);

        std::string temp;
        getline(mystream, temp, ',');
        user.id = stoi(temp);
        std::getline(mystream, user.name, ',');
        getline(mystream, temp, ',');
        user.userType = stoi(temp);
        std::getline(mystream, user.email, ',');
        std::getline(mystream, user.password, ',');
        getline(mystream, temp, ',');
        user.passwordSet = stoi(temp);
        if (!mystream)
            break;

        users.push_back(user);
        rowCount++;
    }
    
    usersFile.close();

    return users;
}

std::vector<Users> Users::getAllByType(int userType) {

    Users users;
    std::vector<Users> temp;
    std::vector<Users> allUsers = users.getAll();
    for (const Users& u : allUsers) {

        if (u.userType == userType) {
            temp.push_back(u);
        }
    }
    return temp;
}

Users Users::getOne(int id) {
    // returns user by ID

    Users users;
    std::vector<Users> allUsers = users.getAll();
    for (const Users& u : allUsers) {
        if (u.id != id) {
            continue;
        }
        else {
            return u;
        }
    }
}

void Users::viewUser(Users user) {
    // ID, Name, Email, User Type
    std::cout << "User ID:       " << user.id << "\n";
    std::cout << "Name:          " << user.name << "\n";
    std::cout << "Email:         " << user.email << "\n";

    std::string type;
    switch (user.userType) {
    case 1:
        type = "Admin";
        break;
    case 2:
        type = "Teacher";
        break;
    case 3:
        type = "Parent";
        break;
    }
    std::cout << "User Type:     " << type << "\n";
    std::cout << "-----------\n\n";
}

bool Users::newUser(string name, int userType, string email, string password) {
    // creates a new user
    Users users;
    int id = 1;
    std::vector<Users> allUsers = users.getAll();

    if (allUsers.size() != 0) {
        id = allUsers.back().id + 1;
    }

    std::ofstream usersFile;
    

    if (allUsers.size() == 0) {
        usersFile.open("users.csv", std::ios::out);
        usersFile << "ID, Name, UserType, Email, Password, PasswordSet\n";
    }
    
    else {
        usersFile.open("users.csv", std::ios::app);
    }

    usersFile << std::to_string(id) << "," << name << "," << userType << "," << email << "," << password << "," << "0\n";
    usersFile.close();
    return true;

}

Users Users::editName(int id, string name) {
    // edits user name
    Users users;
    
    std::vector<Users> allUsers = users.getAll();
    
    usersFile.open("users.csv", std::ios::out);
    usersFile << "ID, Name, UserType, Email, Password, PasswordSet\n";
    for (Users& u : allUsers) {
        
        if (u.id == id) {
            u.name = name;
        }
        usersFile << std::to_string(u.id) << "," << u.name << "," << u.userType << "," << u.email << "," << u.password << "," << std::to_string(u.passwordSet) << "\n";

    }
    usersFile.close();
    
    return users.getOne(id);
}

Users Users::editEmail(int id, string email) {
    // edits user email
    Users users;

    std::vector<Users> allUsers = users.getAll();

    usersFile.open("users.csv", std::ios::out);
    usersFile << "ID, Name, UserType, Email, Password, PasswordSet \n";
    for (Users& u : allUsers) {

        if (u.id == id) {
            u.email = email;
        }
        usersFile << std::to_string(u.id) << "," << u.name << "," << u.userType << "," << u.email << "," << u.password << "," << std::to_string(u.passwordSet) << "\n";

    }
    usersFile.close();

    return users.getOne(id);
}

Users Users::editPassword(int id, string password) {

    Users users;

    std::vector<Users> allUsers = users.getAll();

    usersFile.open("users.csv", std::ios::out);
    usersFile << "ID, Name, UserType, Email, Password, PasswordSet \n";
    for (Users& u : allUsers) {

        if (u.id == id) {
            u.password = password;
            u.passwordSet = 1;
        }
        usersFile << std::to_string(u.id) << "," << u.name << "," << u.userType << "," << u.email << "," << u.password << "," << std::to_string(u.passwordSet) << "\n";

    }
    usersFile.close();

    return users.getOne(id);
}

bool Users::deleteUser(int id) {

    Users users;

    std::vector<Users> allUsers = users.getAll();

    usersFile.open("users.csv", std::ios::out);
    usersFile << "ID, Name, UserType, Email, Password, PasswordSet \n";
    for (Users& u : allUsers) {

        if (u.id != id) {
            usersFile << std::to_string(u.id) << "," << u.name << "," << u.userType << "," << u.email << "," << u.password << "," << std::to_string(u.passwordSet) << "\n";
        }
        
    }
    usersFile.close();

    return true;

}


Users Users::login() {

    std::string inputEmail, inputPassword;
    int attempts = 1;
    Users users;
    std::vector<Users> allUsers = users.getAll();

    while (true) {

        system("cls");
        std::cout << "Email address: ";
        std::cin >> inputEmail;
        std::cout << "Password: ";
        std::cin >> inputPassword;
        for (const Users& u : allUsers) {
            if (u.email == inputEmail && u.password == inputPassword) {
                system("cls");
                std::cout << "Welcome, " << u.name << "\n";
                if (u.passwordSet != 1) {
                    std::string newPass;
                    std::cout << "Please set a new password: ";
                    std::cin >> newPass;
                    users.editPassword(u.id, newPass);
                }
                return u;
            }
        }
        system("cls");
        if (attempts == 3) {
            std::cout << "Maximum attempts tried, try again later";
            break;
        }
        std::cout << "Email and/or password incorrect\n";
        std::cout << "Press try again.\n";
        attempts++;
        std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    }
}