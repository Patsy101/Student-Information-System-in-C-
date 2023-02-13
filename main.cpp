#include <iostream>
#include <vector>
#include <string>
#include "users.h"
#include "students.h"
#include "classes.h"
#include "enrollments.h"
#include "grades.h"
#include "menus.h"


int main()
{

    Users users;
    Menus menus;
    Users loggedInUser = users.login();
    system("cls");
    switch (loggedInUser.userType) {
    case 1:
        menus.menuAdmin(loggedInUser);
        break;

    case 2:
        menus.menuTeacher(loggedInUser);
        break;

    case 3:
        menus.menuParent(loggedInUser);
        break;
    }

}
