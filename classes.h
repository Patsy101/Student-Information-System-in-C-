#ifndef classes_h
#define classes_h

using std::string;

class Classes
{

public:

    int id;
    string name;
    int teacherID;

    std::vector<Classes> getAll();
    std::vector<Classes> getAllByTeacher(int id);
    Classes getOnelByTeacher(int id);
    Classes getOne(int id);
    Classes getOneByTeacherID(int id);
    bool newClass(string name, int teacherID);
    Classes editName(int id, string name);
    Classes editTeacher(int id, int teacherID);
    bool deleteClass(int id);

};

#endif