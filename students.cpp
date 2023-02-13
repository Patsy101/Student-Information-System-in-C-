#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "students.h"

std::fstream studentsFile;

std::vector<Students> Students::getAll() {
    // Returns a vector of all students
    studentsFile.open("students.csv", std::ios::in);

    std::string row;

    std::vector<Students> students;

    int rowCount = 0;
    getline(studentsFile, row); // ignore header line

    Students student;

    while (getline(studentsFile, row) && !row.empty())
    {
        std::stringstream mystream(row);

        std::string temp;
        getline(mystream, temp, ',');
        student.id = stoi(temp);
        std::getline(mystream, student.name, ',');
        getline(mystream, temp, ',');
        student.parentID = stoi(temp);
        if (!mystream)
            break;

        students.push_back(student);
        rowCount++;
    }

    studentsFile.close();

    return students;
}

Students Students::getOne(int id) {
    // returns student by ID

    Students students;
    std::vector<Students> allStudents = students.getAll();
    for (const Students& u : allStudents) {
        if (u.id != id) {
            continue;
        }
        else {
            return u;
        }
    }
}
Students Students::getOneByParent(int id) {
    // returns student by UserID

    Students students;
    std::vector<Students> allStudents = students.getAll();
    for (const Students& u : allStudents) {
        if (u.parentID != id) {
            continue;
        }
        else {
            return u;
        }
    }
}


bool Students::newStudent(string name, int parentID) {

    Students students;
    int id = 1;
    std::vector<Students> allStudents = students.getAll();

    if (allStudents.size() != 0) {
        id = allStudents.back().id + 1;
    }

    std::ofstream studentsFile;


    if (allStudents.size() == 0) {
        studentsFile.open("students.csv", std::ios::out);
        studentsFile << "ID, Name, ParentID\n";
    }

    else {
        studentsFile.open("students.csv", std::ios::app);
    }

    studentsFile << std::to_string(id) << "," << name << "," << parentID << "\n";
    studentsFile.close();
    return true;

}

Students Students::editName(int id, string name) {

    Students students;

    std::vector<Students> allStudents = students.getAll();

    studentsFile.open("students.csv", std::ios::out);
    studentsFile << "ID, Name, ParentID\n";
    for (Students& s : allStudents) {

        if (s.id == id) {
            s.name = name;
        }
        studentsFile << std::to_string(s.id) << "," << s.name << "," << s.parentID << "\n";

    }
    studentsFile.close();

    return students.getOne(id);
}

Students Students::editParent(int id, int parentID) {

    Students students;

    std::vector<Students> allStudents = students.getAll();

    studentsFile.open("students.csv", std::ios::out);
    studentsFile << "ID, Name, ParentID\n";
    for (Students& s : allStudents) {

        if (s.id == id) {
            s.parentID = parentID;
        }
        studentsFile << std::to_string(s.id) << "," << s.name << "," << s.parentID << "\n";

    }
    studentsFile.close();

    return students.getOne(id);
}

void Students::viewUser(Students _student) {
    // ID, Name, Email, User Type
    std::cout << "Student ID:       " << _student.id << "\n";
    std::cout << "Name:          " << _student.name << "\n";
    //std::cout << "Email:         " << user.email << "\n";

    //std::string type;
    //switch (user.userType) {
    //case 1:
    //    type = "Admin";
    //    break;
    //case 2:
    //    type = "Teacher";
    //    break;
    //case 3:
    //    type = "Parent";
    //    break;
    //}
    //std::cout << "User Type:     " << type << "\n";
    //std::cout << "-----------\n\n";
}


bool Students::deleteStudent(int id) {

    Students students;

    std::vector<Students> allStudents = students.getAll();

    studentsFile.open("students.csv", std::ios::out);
    studentsFile << "ID, Name, ParentID\n";
    for (Students& s : allStudents) {

        if (s.id != id) {
            studentsFile << std::to_string(s.id) << "," << s.name << "," << s.parentID << "\n";
        }

    }
    studentsFile.close();

    return true;

}
