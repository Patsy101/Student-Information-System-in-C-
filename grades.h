#ifndef grades_h
#define grades_h

using std::string;

class Grades
{

public:

    int studentID;
    int classID;
    string grade;

    std::vector<Grades> getAll();
    std::vector<Grades> getAllByStudent(int studentID);
    std::vector<Grades> getAllByClass(int classID);
    Grades getOne(int id);
    bool newGrade(int studentID, int classID, string grade);
    bool deleteGrade(int studentID, int classID);

};

#endif