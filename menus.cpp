#include <iostream>
#include <vector>
#include <string>
#include "users.h"
#include "students.h"
#include "classes.h"
#include "enrollments.h"
#include "grades.h"
#include "menus.h"
#include <chrono>
#include <thread>
using namespace std;

void returnToMainMenu() {
    string next;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "___________________________" << std::endl;
    std::cout << std::endl;
    std::cout << "Press any key to return to the main menu" << std::endl;
    std::cin >> next;
}


bool returnToMain() {

    int type;
    std::cout << std::endl;
    std::cout << std::endl;
    std::cout << "1. select a user \n";
    std::cout << "2. return to the menu \n";
    std::cout << std::endl;
    std::cout << std::endl;
    std::cin >> type;
    std::cout << std::endl;

    if (type == 2)
        return false;

    else
        return true;

}

void ShowALlUsers() {
    Users users;
    system("cls");
    std::cout << "Admin Menu :: Users :: View All Users \n";
    std::cout << "-----------\n\n";

    int userSelect;
    std::vector<Users> allUsers = users.getAll();
    for (const Users& u : allUsers) {
        std::cout << u.id << ". " << u.name << "\n";
    }
}


void Menus::menuAdmin(Users users) {

    bool mainMenu = true;
    while (mainMenu) {
        system("cls");
        std::cout << "Admin Menu \n";
        std::cout << "-----------\n\n";

        int userSelect;
        std::cout << "1. Users \n";
        std::cout << "2. Students \n";
        std::cout << "3. Classes \n\n";
        std::cout << "4. Logout \n\n";
        std::cin >> userSelect;

            switch (userSelect) {
            //Admin - Users
            case 1:{

                system("cls");
                std::cout << "Admin Menu :: Users \n";
                std::cout << "-----------\n\n";

                int userSelect;
                std::cout << "1. View All Users \n";
                std::cout << "2. View Admin Users \n";
                std::cout << "3. View Teacher Users \n";
                std::cout << "4. View Parent Users \n\n";
                std::cout << "5. Return to Admin Menu \n\n";
                std::cin >> userSelect;

                        //View All Users 
                        if (userSelect == 1) {
                            bool active = true;
                            while (active) {

                                system("cls");
                                std::cout << "Admin Menu :: Users :: View All Users \n";
                                std::cout << "-----------\n\n";

                                int userSelect;
                                std::vector<Users> allUsers = users.getAll();
                                for (const Users& u : allUsers) {
                                    std::cout << u.id << ". " << u.name << "\n";
                                }

                                //ask for user input to select a user or return to the main menu
                                if (!returnToMain()) {
                                    break;
                                };

                                std::cout << "Please Type an ID number to select a user\n";
                                std::cin >> userSelect;
                                system("cls");
                                Users selectedUser = users.getOne(userSelect);
                                users.viewUser(selectedUser);
                                std::cout << "1. Edit Name \n";
                                std::cout << "2. Edit Email \n";
                                std::cout << "3. Delete User \n\n";
                                std::cout << "4. Return to Admin Menu \n\n";
                                std::cin >> userSelect;
                                
                                        //Edit Name
                                        if (userSelect == 1) {
                                            system("cls");
                                            users.viewUser(selectedUser);

                                            std::string newName;
                                            std::cout << "Enter new name: ";
                                            std::getline(std::cin >> std::ws, newName);

                                            system("cls");
                                            users.viewUser(selectedUser);

                                            std::cout << "1. Confirm name change to: " << newName << "\n";
                                            std::cout << "2. Cancel Changes" << "\n\n";
                                            std::cin >> userSelect;

                                            if (userSelect == 1) {
                                                users.editName(selectedUser.id, newName);
                                                system("cls");
                                                users.viewUser(selectedUser);

                                            }
                                            returnToMainMenu();
                                        }

                                        //Edit Email
                                        else if (userSelect == 2) {
                                            system("cls");
                                            users.viewUser(selectedUser);

                                            std::string newEmail;
                                            std::cout << "Enter new email: ";
                                            std::getline(std::cin >> std::ws, newEmail);

                                            system("cls");
                                            users.viewUser(selectedUser);

                                            std::cout << "1. Confirm email change to: " << newEmail << "\n";
                                            std::cout << "2. Cancel Changes" << "\n\n";
                                            std::cin >> userSelect;

                                            if (userSelect == 1) {
                                                users.editEmail(selectedUser.id, newEmail);
                                                system("cls");
                                                users.viewUser(selectedUser);

                                            }
                                            returnToMainMenu();
                                        }

                                        //Delete User 
                                        else if (userSelect == 3) {
                                            system("cls");
                                            users.viewUser(selectedUser);

                                            std::cout << "1. Confirm delete of: " << selectedUser.name << "\n";
                                            std::cout << "2. Cancel" << "\n\n";
                                            std::cin >> userSelect;

                                            if (userSelect == 1) {
                                                users.deleteUser(selectedUser.id);
                                            }
                                            returnToMainMenu();
                                        }

                                        // return 
                                        else if (userSelect == 4) {
                                            active = false;
                                        }

                                        else {
                                            cout << "error!!" << endl;
                                        }
                            } // End of active loop
                            break;
                        }
                        //View Admin Users
                        else if (userSelect == 2) {
                            bool active = true;
                            while (active) {
                                system("cls");
                                std::cout << "Admin Menu :: Users :: View All Admin Users \n";
                                std::cout << "-----------\n\n";

                                int userSelect;
                                std::vector<Users> allUsers = users.getAllByType(1);
                                for (const Users& u : allUsers) {
                                    std::cout << u.id << ". " << u.name << "\n";
                                };
                                if (!returnToMain()) {
                                    break;
                                };

                                std::cout << "Please Type an ID number to select a user\n";
                                std::cin >> userSelect;
                                system("cls");
                                Users selectedUser = users.getOne(userSelect);
                                users.viewUser(selectedUser);
                                std::cout << "1. Edit Name \n";
                                std::cout << "2. Edit Email \n";
                                std::cout << "3. Delete User \n\n";
                                std::cout << "4. Return to Admin Menu \n\n";
                                std::cin >> userSelect;

                                //edit name
                                if (userSelect == 1) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::string newName;
                                    std::cout << "Enter new name: ";
                                    std::getline(std::cin >> std::ws, newName);

                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm name change to: " << newName << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        Users changedUser = users.editName(selectedUser.id, newName);
                                        system("cls");
                                        users.viewUser(selectedUser);

                                    }

                                }

                                //Edit Email
                                else if (userSelect == 2) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::string newEmail;
                                    std::cout << "Enter new email: ";
                                    std::getline(std::cin >> std::ws, newEmail);

                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm email change to: " << newEmail << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        users.editEmail(selectedUser.id, newEmail);
                                        system("cls");
                                        users.viewUser(selectedUser);

                                    }

                                }

                                //Delete User
                                else if (userSelect == 3) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm delete of: " << selectedUser.name << "\n";
                                    std::cout << "2. Cancel" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        users.deleteUser(selectedUser.id);
                                    }

                                }

                                //Return to Admin Menu 
                                else if (userSelect == 4) {
                                    active = false;
                                }
                            } // End of active loop
                            break;
                        }
                        //View Teacher Users
                        else if (userSelect == 3) {
                            bool active = true;
                            while (active) {
                                system("cls");
                                std::cout << "Admin Menu :: Users :: View All Admin Users \n";
                                std::cout << "-----------\n\n";

                                int userSelect;
                                std::vector<Users> allUsers = users.getAllByType(2);
                                for (const Users& u : allUsers) {
                                    std::cout << u.id << ". " << u.name << "\n";
                                };
                                if (!returnToMain()) {
                                    break;
                                };

                                std::cout << "Please Type an ID number to select a user\n";
                                std::cin >> userSelect;
                                system("cls");
                                Users selectedUser = users.getOne(userSelect);
                                users.viewUser(selectedUser);
                                std::cout << "1. Edit Name \n";
                                std::cout << "2. Edit Email \n";
                                std::cout << "3. Delete User \n\n";
                                std::cout << "4. Return to Admin Menu \n\n";
                                std::cin >> userSelect;

                                //edit name
                                if (userSelect == 1) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::string newName;
                                    std::cout << "Enter new name: ";
                                    std::getline(std::cin >> std::ws, newName);

                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm name change to: " << newName << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        Users changedUser = users.editName(selectedUser.id, newName);
                                        system("cls");
                                        users.viewUser(selectedUser);

                                    }

                                }

                                //Edit Email
                                else if (userSelect == 2) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::string newEmail;
                                    std::cout << "Enter new email: ";
                                    std::getline(std::cin >> std::ws, newEmail);

                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm email change to: " << newEmail << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        users.editEmail(selectedUser.id, newEmail);
                                        system("cls");
                                        users.viewUser(selectedUser);

                                    }

                                }

                                //Delete User
                                else if (userSelect == 3) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm delete of: " << selectedUser.name << "\n";
                                    std::cout << "2. Cancel" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        users.deleteUser(selectedUser.id);
                                    }

                                }

                                //Return to Admin Menu 
                                else if (userSelect == 4) {
                                    active = false;
                                }
                            } // End of active loop
                            break;
                        }
                        //View Parent Users
                        else if (userSelect == 4) {
                            bool active = true;
                            while (active) {
                                system("cls");
                                std::cout << "Admin Menu :: Users :: View All Admin Users \n";
                                std::cout << "-----------\n\n";

                                int userSelect;
                                std::vector<Users> allUsers = users.getAllByType(3);
                                for (const Users& u : allUsers) {
                                    std::cout << u.id << ". " << u.name << "\n";
                                };
                                if (!returnToMain()) {
                                    break;
                                };

                                std::cout << "Please Type an ID number to select a user\n";
                                std::cin >> userSelect;
                                system("cls");
                                Users selectedUser = users.getOne(userSelect);
                                users.viewUser(selectedUser);
                                std::cout << "1. Edit Name \n";
                                std::cout << "2. Edit Email \n";
                                std::cout << "3. Delete User \n\n";
                                std::cout << "4. Return to Admin Menu \n\n";
                                std::cin >> userSelect;

                                //edit name
                                if (userSelect == 1) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::string newName;
                                    std::cout << "Enter new name: ";
                                    std::getline(std::cin >> std::ws, newName);

                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm name change to: " << newName << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        Users changedUser = users.editName(selectedUser.id, newName);
                                        system("cls");
                                        users.viewUser(selectedUser);

                                    }

                                }

                                //Edit Email
                                else if (userSelect == 2) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::string newEmail;
                                    std::cout << "Enter new email: ";
                                    std::getline(std::cin >> std::ws, newEmail);

                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm email change to: " << newEmail << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        users.editEmail(selectedUser.id, newEmail);
                                        system("cls");
                                        users.viewUser(selectedUser);

                                    }

                                }

                                //Delete User
                                else if (userSelect == 3) {
                                    system("cls");
                                    users.viewUser(selectedUser);

                                    std::cout << "1. Confirm delete of: " << selectedUser.name << "\n";
                                    std::cout << "2. Cancel" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        users.deleteUser(selectedUser.id);
                                    }

                                }

                                //Return to Admin Menu 
                                else if (userSelect == 4) {
                                    active = false;
                                }
                            } // End of active loop
                            break;
                        }
                        //Return to Admin Menu
                        else if (userSelect == 5) {
                            break;
                        }

                        else {
                            std::cout << "error detection \n";
                        }
                    }

            //Admin - Students
            case 2: {
                system("cls");
                std::cout << "Admin Menu :: Students \n";
                std::cout << "-----------\n\n";

                int userSelect;
                std::cout << "1. View All Students \n";
                std::cout << "2. View Students by Class\n";
                std::cout << "3. Add a New Student  \n";
                std::cout << "4. Return to Admin Menu \n\n";
                std::cin >> userSelect;

                        //View All Students 
                        if (userSelect == 1) {
                            bool active = true;
                            while (active) {
                                system("cls");
                                std::cout << "Admin Menu :: Students :: View All Students \n";
                                std::cout << "-----------\n\n";

                                int userSelect;
                                Students student;
                                std::vector<Students> allStudents = student.getAll();
                                for (const Students& u : allStudents) {
                                    std::cout << u.id << ". " << u.name << "\n";
                                }

                                //ask for user input to select a user or return to the main menu
                                if (!returnToMain()) {
                                    break;
                                };

                                std::cout << "Please Type an ID number to select a student\n";

                                std::cin >> userSelect;
                                system("cls");
                                Students selectedUser = student.getOne(userSelect);
                                student.viewUser(selectedUser);
                                std::cout << "1. Edit an existing student \n";
                                std::cout << "2. Delete student \n\n";
                                std::cout << "3. Return to Admin Menu \n\n";
                                std::cin >> userSelect;

                                //Edit an existing student
                                     if (userSelect == 1) {


                                        system("cls");
                                        student.viewUser(selectedUser);

                                        std::string newName;
                                        std::cout << "Enter new name: ";
                                        std::getline(std::cin >> std::ws, newName);

                                        system("cls");
                                        student.viewUser(selectedUser);

                                        std::cout << "1. Confirm name change to: " << newName << "\n";
                                        std::cout << "2. Cancel Changes" << "\n\n";
                                        std::cin >> userSelect;

                                        if (userSelect == 1) {
                                            student.editName(selectedUser.id, newName);
                                            system("cls");
                                            student.viewUser(selectedUser);

                                        }
                                        active = false;
                                        returnToMainMenu();
                                        break;
                                    }
                                //Delete a student
                                    else if (userSelect == 2) {

                                        system("cls");
                                        student.viewUser(selectedUser);

                                        std::cout << "1. Confirm delete of: " << selectedUser.name << "\n";
                                        std::cout << "2. Cancel" << "\n\n";
                                        std::cin >> userSelect;

                                        if (userSelect == 1) {
                                            student.deleteStudent(selectedUser.id);
                                        }

                                        break;
                                        returnToMainMenu();
                                        active = false;
                                    }
                                //Return to Admin Menu
                                    else if (userSelect == 3) {
                                        active = false;
                                        returnToMainMenu();
                                        break;
                                    }

                                    else  {
                                        cout << "ERORR Detection!!!" << endl;
                                    }


                            } // End of active loop
                            break;
                        }
                        //View Students by class 
                        else if (userSelect == 2) {

                            bool active = true;
                            while (active) {
                                Classes classroom;

                                system("cls");
                                std::cout << "Admin Menu :: Users :: View All students by class \n";
                                std::cout << "-----------\n\n";

                                int userSelect;
                                std::vector<Classes> allUclasses = classroom.getAll();
                                for (const Classes& u : allUclasses) {
                                    std::cout <<"class number : " << u.id << "  Class Name : " << u.name << "  Teacher's ID : " << u.teacherID << "\n";
                                };

                                //ask for user input to select a user or return to the main menu
                                if (!returnToMain()) {
                                    break;
                                };

                                std::cout << "Please Type an ID number to select a student\n";

                                std::cin >> userSelect;
                                system("cls");

                                Enrollments enrollment;
                                std::vector <Enrollments> enrollmentList = enrollment.getAllByClass(userSelect);
                                for (const Enrollments& u : enrollmentList)
                                {
                                    Students list = list.getOne(u.studentID);
                                    std::cout << "student ID: " << list.id << "   " << "Student Name: " << list.name << std::endl;
                                };

                                returnToMainMenu();

                            } // End of active loop
                            active = false;
                            break;
                        }
                        // add a new student
                        else if (userSelect == 3) {
                        system("cls");
                        std::cout << "Admin Menu :: Students :: Add a new student\n";
                        std::cout << "-----------\n\n";


                        int newParentID;
                        string newStudentName;
                        Students student;
                        cout << "Please enter parent ID : ";
                        cin >> newParentID;
                        cout << "Please enter new student name : ";
                        cin >> newStudentName ;

                        std::cout << std::endl << std::endl;
                        std::cout << "-----------\n\n";
                        std::cout << "A new student will be added \n";
                        std::cout << "Name : " << newStudentName << std::endl;
                        std::cout << "Parent ID : " << newParentID << std::endl << std::endl;



                        std::cout << std::endl << std::endl;
                        std::cout << "-----------\n\n";
                        std::cout << "1. Create a new student data \n";
                        std::cout << "2. Cancel changes" << "\n\n";


                        std::cin >> userSelect;
                        if (userSelect == 1) {
                            student.newStudent(newStudentName, newParentID);

                            student = student.getOneByParent(newParentID);

                            system("cls");
                            std::cout << "Admin Menu :: Students :: Add a student\n";
                            std::cout << "-----------\n\n";
                            std::cout << "Student ID : " << student.id << std::endl;
                            std::cout << "Student Name : " << student.name << std::endl;
                            std::cout << "Student Parent ID: " << student.parentID << std::endl;
                        }
                        returnToMainMenu();
                        break;

                        }
                        ////Return to Admin menu
                        else if (userSelect == 4) {
            
                     
                        break;
                        
                            } // End of active loop
                        else {
                            std::cout << "error detection \n";
                        }
                        break;
            }

            //Admin - Classes
            case 3: {
                system("cls");
                std::cout << "Admin Menu :: Classes \n";
                std::cout << "-----------\n\n";

                int userSelect;
                std::cout << "1. View All Classes \n";
                std::cout << "2. Add a New class  \n";
                std::cout << "3. Return to Admin Menu \n\n";
                std::cin >> userSelect;

                //View All classes 
                if (userSelect == 1) {

                    bool active = true;
                    while (active) {
                        active = true;
                        Classes classroom;

                        system("cls");
                        std::cout << "Admin Menu :: Classes :: View All students by class \n";
                        std::cout << "-----------\n\n";

                        int userSelect;
                        std::vector<Classes> allUclasses = classroom.getAll();
                        for (const Classes& u : allUclasses) {
                            std::cout << "class number : " << u.id << "  Class Name : " << u.name << "  Teacher's ID : " << u.teacherID << "\n";
                        };

                        //ask for user input to select a user or return to the main menu
                        if (!returnToMain()) {
                            break;
                        }
                        else {

                                std::cout << "Please Type an ID number to select a class\n";
                                std::cin >> userSelect;

                                system("cls");
                                classroom = classroom.getOne(userSelect);
                                std::cout << "Class ID: " << classroom.id << std::endl;
                                std::cout << "Class Name:  " << classroom.name << std::endl;
                                std::cout << "Teacher ID:  " << classroom.teacherID << std::endl << std::endl;


                                std::cout << "1. Edit class Name \n";
                                std::cout << "2. Edit the Teacher of the class\n";
                                std::cout << "3. Delete a class \n\n";
                                std::cout << "4. Return to Admin Menu \n\n";
                                std::cin >> userSelect;

                                
                                //Edit class Name
                                if (userSelect == 1) {
                                    system("cls");
                                    classroom.getOne(userSelect);
                                    std::cout << "Class ID: " << classroom.id << std::endl;
                                    std::cout << "Class Name:  " << classroom.name << std::endl;
                                    std::cout << "Teacher ID:  " << classroom.teacherID << std::endl << std::endl;


                                    std::string newName;
                                    std::cout << "Enter new name: ";
                                    std::getline(std::cin >> std::ws, newName);

                                    system("cls");
                                    classroom.getOne(userSelect);
                                    std::cout << "Class ID: " << classroom.id << std::endl;
                                    std::cout << "Class Name:  " << classroom.name << std::endl;
                                    std::cout << "Teacher ID:  " << classroom.teacherID << std::endl << std::endl;


                                    std::cout << "1. Confirm name change to: " << newName << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        Classes newNameEdited = classroom.editName(classroom.id, newName);
                                        system("cls");
                                        std::cout << "class ID: " << newNameEdited.id << std::endl;
                                        std::cout << "New class Name:  " << newNameEdited.name << std::endl;
                                        std::cout << "Teacher ID:  " << newNameEdited.teacherID << std::endl << std::endl;


                                    }

                                    returnToMainMenu();
                                }

                                //Edit the Teacher of the class

                                else if (userSelect == 2) {
                                    system("cls");
                                    classroom.getOne(userSelect);
                                    std::cout << "Class ID: " << classroom.id << std::endl;
                                    std::cout << "Class Name:  " << classroom.name << std::endl;
                                    std::cout << "Teacher ID:  " << classroom.teacherID << std::endl << std::endl;

                                    string temp;
                                    int newTeacherID;
                                    std::cout << "Enter a New Teacher's ID: ";
                                    std::getline(std::cin >> std::ws, temp);
                                    newTeacherID = stoi(temp);

                                    system("cls");
                                    classroom.getOne(userSelect);
                                    std::cout << "Class ID: " << classroom.id << std::endl;
                                    std::cout << "Class Name:  " << classroom.name << std::endl;
                                    std::cout << "Teacher ID:  " << classroom.teacherID << std::endl << std::endl;


                                    std::cout << "1. Confirm name change to: " << newTeacherID << "\n";
                                    std::cout << "2. Cancel Changes" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        Classes newNameEdited = classroom.editTeacher(classroom.id, newTeacherID);
                                        system("cls");
                                        std::cout << "class ID: " << newNameEdited.id << std::endl;
                                        std::cout << "New class Name:  " << newNameEdited.name << std::endl;
                                        std::cout << "Teacher ID:  " << newNameEdited.teacherID << std::endl << std::endl;


                                    }

                                    returnToMainMenu();
                                }

                                
                                //Delete a class 
                                else if (userSelect == 3) {
                                    system("cls");
                                    classroom.getOne(userSelect);
                                    std::cout << "Class ID: " << classroom.id << std::endl;
                                    std::cout << "Class Name:  " << classroom.name << std::endl;
                                    std::cout << "Teacher ID:  " << classroom.teacherID << std::endl << std::endl;



                                    std::cout << "1. Confirm delete of: " << classroom.id << std::endl;
                                    std::cout << " classroom's name: " << classroom.name << std::endl;
                                    std::cout << "2. Cancel" << "\n\n";
                                    std::cin >> userSelect;

                                    if (userSelect == 1) {
                                        classroom.deleteClass(classroom.id);
                                    }
                                    returnToMainMenu();


                                }

                                // Return to Admin Menu
                                else if (userSelect == 4) {
                                    active = false;
                                }
                            
                                //error
                                else {
                                    cout << "error!!" << endl;
                                }
                                active = false;
                                break;
                           
                        }
                    } // End of active loop


                }


                // add a new class
                else if (userSelect == 2) {
                    Classes classroom;
                    system("cls");
                    std::cout << "Admin Menu :: Classes :: Add a new class\n";
                    std::cout << "-----------\n\n";


                    int newTeacherID;
                    string newClassName;
                    cout << "Please enter Teacher's ID : ";
                    cin >> newTeacherID;
                    cout << "Please enter a new class name : ";
                    cin >> newClassName;

                    std::cout << std::endl << std::endl;
                    std::cout << "-----------\n\n";
                    std::cout << "A new class will be added \n";
                    std::cout << "Name : " << newClassName << std::endl;
                    std::cout << "Parent ID : " << newTeacherID << std::endl << std::endl;



                    std::cout << std::endl << std::endl;
                    std::cout << "-----------\n\n";
                    std::cout << "1. Create a new student data \n";
                    std::cout << "2. Cancel changes" << "\n\n";


                    std::cin >> userSelect;
                    if (userSelect == 1) {
                        classroom.newClass(newClassName, newTeacherID);

                        classroom = classroom.getOneByTeacherID(newTeacherID);

                        system("cls");
                        std::cout << "Admin Menu :: Students :: Add a student\n";
                        std::cout << "-----------\n\n";
                        std::cout << "New Class ID : " << classroom.id << std::endl;
                        std::cout << "New Class Name : " << classroom.name << std::endl;
                        std::cout << "New Teacher's ID: " << classroom.teacherID << std::endl;
                    }
                    returnToMainMenu();
                    break;

                }
                ////Return to Admin menu
                else if (userSelect == 3) {


                    break;

                } // End of active loop
                else {
                    std::cout << "error detection \n";
                }
                break;
            }

             //Logout
            case 4: {
                mainMenu = false;
                break;
            }
            }

    } // End of main menu loop
}

void Menus::menuTeacher(Users _loggedInUser) {


    Grades grades;
    Students students;
    Enrollments enrollment;
    Classes classroom = classroom.getOnelByTeacher(_loggedInUser.id);
    std::vector <Enrollments> enrollmentList = enrollment.getAllByClass(classroom.id);

    std::cout << "Teacher Menu";
    bool mainMenu = true;

    while (mainMenu) {
        mainMenu = true;
        system("cls");
        std::cout << "Teacher Menu \n";
        std::cout << "-----------\n\n";

        int userSelect = 0;
        std::cout << "1. Students \n";
        std::cout << "2. Logout \n\n";
        std::cin >> userSelect;

        switch (userSelect) {
        case 1:
        {
            //Teacher - Students
            system("cls");
            std::cout << "Teacher Menu :: Students \n";
            std::cout << "-----------\n\n";

            int userSelect;
            std::cout << "1. View Students record \n";
            std::cout << "2. View One Student\n";
            std::cout << "3. Return to Teacher Menu \n\n";
            std::cin >> userSelect;
            bool active = true;
            string next;

            //get all students in a class
            if (userSelect == 1) {

                userSelect = 0;
                system("cls");
                std::cout << "Teacher Menu :: All Students :: View All Students \n";
                std::cout << "-----------\n\n";


                //display all students in a class
                for (const Enrollments& u : enrollmentList)
                {
                    Students list = list.getOne(u.studentID);
                    std::cout << "student ID: " << list.id << "   " << "Student Name: " << list.name << std::endl;
                };


                //show next action menu 
                std::cout << std::endl;
                std::cout << std::endl;
                std::cout << "___________________________" << std::endl;
                std::cout << std::endl;
                std::cout << "Press any key to return to the main menu" << std::endl;
                std::cin >> next;

            }
            //get one students in a class
            else if (userSelect == 2) {

                system("cls");
                std::cout << "Teacher Menu :: One Student :: View One Student \n";
                std::cout << "-----------\n\n";

                for (const Enrollments& u : enrollmentList)
                {
                    Students list = list.getOne(u.studentID);
                    std::cout << "student ID: " << list.id << "   " << "Student Name: " << list.name << std::endl;
                };

                std::cout << std::endl << std::endl;
                std::cout << "Please enter the ID number to view a student's record" << std::endl;
                int inputNumber;
                std::cin >> inputNumber;

                system("cls");
                std::cout << "Teacher Menu :: One Student :: View One Student \n";
                std::cout << "-----------\n\n";

                Grades listGrade = grades.getOne(inputNumber);
                Students listStudent = students.getOne(inputNumber);
                Classes listClass = classroom.getOne(listGrade.classID);

                std::cout << "Student ID : " << listGrade.studentID << std::endl;
                std::cout << "Student Name : " << listStudent.name << std::endl;
                std::cout << "Class Name : " << listClass.name << std::endl;
                std::cout << "Student's Grade : " << listGrade.grade << std::endl;

                std::cout << "___________________________" << std::endl;
                std::cout << std::endl;
                std::cout << "Do you want to add a student's new record?" << std::endl;
                std::cout << std::endl;
                std::cout << "1. Yes \n";
                std::cout << "2. Return to Teacher Menu \n\n";


                userSelect = 0;
                std::cin >> userSelect;

                if (userSelect == 1) {
                    system("cls");
                    std::cout << "Teacher Menu :: One Student :: ADD record \n";
                    std::cout << "-----------\n\n";
                    std::cout << "Student ID : " << listGrade.studentID << std::endl;
                    std::cout << "Student Name : " << listStudent.name << std::endl;
                    std::cout << "Class Name : " << listClass.name << std::endl;
                    std::cout << "Student's Grade : " << listGrade.grade << std::endl;
                    std::cout << "___________________________" << std::endl;
                    std::cout << std::endl;
                    string gradeInput;
                    std::cout << "Please add a value to the record of " << listStudent.name << std::endl;
                    std::cout << std::endl;
                    std::cin >> gradeInput;

                    system("cls");
                    std::cout << "Teacher Menu :: One Student :: ADD record \n";
                    std::cout << "-----------\n\n";
                    std::cout << "Student ID : " << listGrade.studentID << std::endl;
                    std::cout << "Student Name : " << listStudent.name << std::endl;
                    std::cout << "Class Name : " << listClass.name << std::endl;
                    std::cout << "Student's Grade : " << listGrade.grade << std::endl;
                    std::cout << std::endl;

                    std::cout << "1. Confirm grade change to: " << gradeInput << "\n";
                    std::cout << "2. Cancel Changes" << "\n\n";
                    std::cin >> userSelect;

                    if (userSelect == 1) {
                        //grade string??
                        listGrade.grade = gradeInput;
                        system("cls");
                        std::cout << "Teacher Menu :: One Student :: ADD record \n";
                        std::cout << "-----------\n\n";


                        std::cout << "Student ID : " << listGrade.studentID << std::endl;
                        std::cout << "Student Name : " << listStudent.name << std::endl;
                        std::cout << "Class Name : " << listClass.name << std::endl;
                        std::cout << "Student's Grade : " << listGrade.grade << std::endl;
                        std::cout << std::endl;

                        std::cout << "The record has been changed as below" << std::endl;
                        std::cout << std::endl;
                        std::cout << "Please type any key to return the main menu" << std::endl;
                        std::cout << std::endl;
                        std::cin >> next;
                    }

                    else 
                        break;
                }



            }
            //get return to the menu
            else if (userSelect == 3) {
                break;
            }
            //error detection
            else {
                break;
            }

            mainMenu = true;
            break;
        }

        //end the application
        case 2:
        {
            //Logout
            mainMenu = false;
            break;
        }

        } // End of main menu loop
    }
    //void Menus::menuParent(Users users) {
    //    std::cout << "Parent Menu";
    //
    //
    //}
}

void Menus::menuParent(Users _loggedInUser) {


    Grades grades;
    Students studentParents = studentParents.getOneByParent(_loggedInUser.id);
    string next;
    std::cout << studentParents.id<< std::endl;



    std::cout << "Parent Menu";
    bool mainMenu = true;

    while (mainMenu) {
        mainMenu = true;
        system("cls");
        std::cout << "Parent Menu \n";
        std::cout << "-----------\n\n";

        int userSelect = 0;
        std::cout << "1. View Record \n";
        std::cout << "2. Logout \n\n";
        std::cin >> userSelect;

        switch (userSelect) {
        case 1:
        {
        //Parent- Students
        mainMenu = true;

        system("cls");
        std::cout << "Parent Menu :: View Student's record\n";
        std::cout << "-----------\n\n";
        Grades listGrade = listGrade.getOne(studentParents.id);
        Students listStudent = listStudent.getOne(studentParents.id);
        Classes listClass = listClass.getOne(listGrade.classID);

        std::cout << "Student ID : " << listGrade.studentID << std::endl;
        std::cout << "Student Name : " << listStudent.name << std::endl;
        std::cout << "Class Name : " << listClass.name << std::endl;
        std::cout << "Student's Grade : " << listGrade.grade << std::endl;

        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << "___________________________" << std::endl;
        std::cout << std::endl;
        std::cout << "Press any key to return to the main menu" << std::endl;
        std::cin >> next;


            mainMenu = true;
            break;
        }

        //end the application
        case 2:
        {
            //Logout
            mainMenu = false;
            break;
        }

        } // End of main menu loop
    }

}