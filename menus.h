#ifndef menus_h
#define menus_h

#include "users.h"
using std::string;

class Menus
{

public:

    void menuAdmin(Users users);
    void menuTeacher(Users users);
    void menuParent(Users users);
};

#endif
