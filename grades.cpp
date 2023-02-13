#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "grades.h"

std::fstream gradesFile;

std::vector<Grades> Grades::getAll() {
    // Returns a vector of all grades
    gradesFile.open("grades.csv", std::ios::in);

    std::string row;

    std::vector<Grades> grades;

    int rowCount = 0;
    getline(gradesFile, row); // ignore header line

    Grades grade;

    while (getline(gradesFile, row) && !row.empty())
    {
        std::stringstream mystream(row);

        //the order of classID and studentID swapped based on the shared diagram
        std::string temp;
        getline(mystream, temp, ',');
        grade.classID = stoi(temp);
        getline(mystream, temp, ',');
        grade.studentID = stoi(temp);
        std::getline(mystream, grade.grade, ',');
        if (!mystream)
            break;

        grades.push_back(grade);
        rowCount++;
    }

    gradesFile.close();

    return grades;
}

Grades Grades::getOne(int id) {
    // returns student's grade by ID

    Grades grades;
    std::vector<Grades> allSGrades = grades.getAll();
    for (const Grades& u : allSGrades) {
        if (u.studentID != id) {
            continue;
        }
        else {
            return u;
        }
    }
}



std::vector<Grades> Grades::getAllByStudent(int studentID) {
    // returns grades by student

    std::vector<Grades> grades;
    Grades grade;
    std::vector<Grades> allGrades = grade.getAll();
    for (const Grades& g : allGrades) {
        if (g.studentID == studentID) {
            grades.push_back(g);
        }
    }
    return grades;
}

std::vector<Grades> Grades::getAllByClass(int classID) {
    // returns grades by student

    std::vector<Grades> grades;
    Grades grade;
    std::vector<Grades> allGrades = grade.getAll();
    for (const Grades& g : allGrades) {
        if (g.classID == classID) {
            grades.push_back(g);
        }
    }
    return grades;
}

bool Grades::newGrade(int studentID, int classID, string grade) {

    Grades grades;
    std::vector<Grades> allClasses = grades.getAll();

    std::ofstream gradesFile;


    if (allClasses.size() == 0) {
        gradesFile.open("grades.csv", std::ios::out);
        gradesFile << "StudentID, ClassID, Grade\n";
    }

    else {
        gradesFile.open("grades.csv", std::ios::app);
    }

    gradesFile << std::to_string(studentID) << "," << std::to_string(classID)<< "," << grade << "\n";
    gradesFile.close();
    return true;

}

bool Grades::deleteGrade(int studentID, int classID) {

    Grades grades;

    std::vector<Grades> allGrades = grades.getAll();

    gradesFile.open("grades.csv", std::ios::out);
    gradesFile << "studentID, classID, Grade\n";
    for (Grades& g : allGrades) {

        if (g.studentID == studentID && g.classID == classID) {
            continue;
        }
        else {
            gradesFile << std::to_string(g.studentID) << "," << std::to_string(g.classID) << "," << g.grade << "\n";
        }

    }
    gradesFile.close();

    return true;

}