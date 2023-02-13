#ifndef students_h
#define students_h

using std::string;

class Students
{

public:

    int id;
    string name;
    int parentID;

    std::vector<Students> getAll();
    Students getOne(int id);
    Students getOneByParent(int id);
    bool newStudent(string name, int parentID);
    void viewUser(Students student);
    Students editName(int id, string name);
    Students editParent(int id, int parentID);
    bool deleteStudent(int id);

};

#endif
