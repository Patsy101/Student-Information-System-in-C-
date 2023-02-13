#ifndef users_h
#define users_h

using std::string;

class Users
{

public:

    int id;
    string name;
    int userType;
    string email;
    string password;
    int passwordSet;

    std::vector<Users> getAll();
    std::vector<Users> getAllByType(int userType);
    Users getOne(int id);
    void viewUser(Users user);
    bool newUser(string name, int userType, string email, string password);
    Users editName(int id, string name);
    Users editEmail(int id, string email);
    Users editPassword(int id, string password);
    bool deleteUser(int id);

    Users login();

};

#endif