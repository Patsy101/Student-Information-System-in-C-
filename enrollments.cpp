#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "enrollments.h"

std::fstream enrollmentsFile;

std::vector<Enrollments> Enrollments::getAll() {
    // Returns a vector of all enrollments
    enrollmentsFile.open("enrollments.csv", std::ios::in);

    std::string row;

    std::vector<Enrollments> enrollments;

    int rowCount = 0;
    getline(enrollmentsFile, row); // ignore header line

    Enrollments enrollment;

    while (getline(enrollmentsFile, row) && !row.empty())
    {
        std::stringstream mystream(row);


        //fixed the order of classID and StudetnID according to the project overview png file
        //revert this change if necessary 
        std::string temp;
        getline(mystream, temp, ',');
        enrollment.classID = stoi(temp);
        getline(mystream, temp, ',');
        enrollment.studentID = stoi(temp);

        if (!mystream)
            break;

        enrollments.push_back(enrollment);
        rowCount++;
    }

    enrollmentsFile.close();

    return enrollments;
}

std::vector<Enrollments> Enrollments::getAllByStudent(int studentID) {
    // returns enrollments by student

    std::vector<Enrollments> enrollments;
    Enrollments enrollment;
    std::vector<Enrollments> allEnrollments = enrollment.getAll();
    for (const Enrollments& e : allEnrollments) {
        if (e.studentID == studentID) {
            enrollments.push_back(e);
        }
    }
    return enrollments;
}

std::vector<Enrollments> Enrollments::getAllByClass(int classID) {
    // returns enrollments by student

    std::vector<Enrollments> enrollments;
    Enrollments enrollment;
    std::vector<Enrollments> allEnrollments = enrollment.getAll();
    for (const Enrollments& e : allEnrollments) {
        if (e.classID == classID) {
            enrollments.push_back(e);
        }
    }
    return enrollments;
}

bool Enrollments::newEnrollment(int studentID, int classID) {

    Enrollments enrollments;
    std::vector<Enrollments> allClasses = enrollments.getAll();

    std::ofstream enrollmentsFile;


    if (allClasses.size() == 0) {
        enrollmentsFile.open("enrollments.csv", std::ios::out);
        enrollmentsFile << "StudentID, ClassID\n";
    }

    else {
        enrollmentsFile.open("enrollments.csv", std::ios::app);
    }

    enrollmentsFile << std::to_string(studentID) << "," << std::to_string(classID) << "\n";
    enrollmentsFile.close();
    return true;

}

bool Enrollments::deleteEnrollment(int studentID, int classID) {

    Enrollments enrollments;

    std::vector<Enrollments> allEnrollments = enrollments.getAll();

    enrollmentsFile.open("enrollments.csv", std::ios::out);
    enrollmentsFile << "studentID, classID\n";
    for (Enrollments& e : allEnrollments) {

        if (e.studentID == studentID && e.classID == classID) {
            continue;
        }
        else {
            enrollmentsFile << std::to_string(e.studentID) << "," << std::to_string(e.classID) << "\n";
        }
    }
    enrollmentsFile.close();

    return true;

}