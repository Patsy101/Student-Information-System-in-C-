#ifndef enrollments_h
#define enrollments_h

using std::string;

class Enrollments
{

public:

    int studentID;
    int classID;

    std::vector<Enrollments> getAll();
    std::vector<Enrollments> getAllByStudent(int studentID);
    std::vector<Enrollments> getAllByClass(int classID);
    bool newEnrollment(int studentID, int classID);
    bool deleteEnrollment(int studentID, int classID);

};

#endif