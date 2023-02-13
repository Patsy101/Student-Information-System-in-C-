#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include "classes.h"

std::fstream classesFile;

std::vector<Classes> Classes::getAll() {
    // Returns a vector of all classes
    classesFile.open("classes.csv", std::ios::in);

    std::string row;

    std::vector<Classes> classes;

    int rowCount = 0;
    getline(classesFile, row); // ignore header line

    Classes classe;

    while (getline(classesFile, row) && !row.empty())
    {
        std::stringstream mystream(row);

        std::string temp;
        getline(mystream, temp, ',');
        classe.id = stoi(temp);
        std::getline(mystream, classe.name, ',');
        getline(mystream, temp, ',');
        classe.teacherID = stoi(temp);
        if (!mystream)
            break;

        classes.push_back(classe);
        rowCount++;
    }

    classesFile.close();

    return classes;
}

std::vector<Classes> Classes::getAllByTeacher(int id) {
    // returns classe by ID

    Classes classes;
    std::vector<Classes> temp;
    std::vector<Classes> allClasses = classes.getAll();
    for (const Classes& u : allClasses) {
        if (u.teacherID == id) {
            temp.push_back(u);
        }
    }
    return temp;
}

Classes Classes::getOnelByTeacher(int id) {
    // returns classe by ID

    Classes classes;
    std::vector<Classes> allClasses = classes.getAll();
    for (const Classes& u : allClasses) {
        if (u.teacherID != id) {
            continue;
        }
        else {
            return u;
        }
    }
}

Classes Classes::getOne(int id) {
    // returns classe by ID

    Classes classes;
    std::vector<Classes> allClasses = classes.getAll();
    for (const Classes& u : allClasses) {
        if (u.id != id) {
            continue;
        }
        else {
            return u;
            break;
        }

    }

}

Classes Classes::getOneByTeacherID(int Teachersid) {
    // returns classe by Teacher's ID

    Classes classes;
    std::vector<Classes> allClasses = classes.getAll();
    for (const Classes& u : allClasses) {
        if (u.teacherID != Teachersid) {
            continue;
        }
        else {

            return u;
            break;
        }

    }

}

bool Classes::newClass(string name, int teacherID) {

    Classes classes;
    int id = 1;
    std::vector<Classes> allClasses = classes.getAll();

    if (allClasses.size() != 0) {
        id = allClasses.back().id + 1;
    }

    std::ofstream classesFile;


    if (allClasses.size() == 0) {
        classesFile.open("classes.csv", std::ios::out);
        classesFile << "ID, Name, TeacherID\n";
    }

    else {
        classesFile.open("classes.csv", std::ios::app);
    }

    classesFile << std::to_string(id) << "," << name << "," << teacherID << "\n";
    classesFile.close();
    return true;

}

Classes Classes::editName(int id, string name) {

    Classes classes;

    std::vector<Classes> allClasses = classes.getAll();

    classesFile.open("classes.csv", std::ios::out);
    classesFile << "ID, Name, TeacherID\n";
    for (Classes& c : allClasses) {

        if (c.id == id) {
            c.name = name;
        }
        classesFile << std::to_string(c.id) << "," << c.name << "," << c.teacherID << "\n";

    }
    classesFile.close();

    return classes.getOne(id);
}

Classes Classes::editTeacher(int id, int teacherID) {

    Classes classes;

    std::vector<Classes> allClasses = classes.getAll();

    classesFile.open("classes.csv", std::ios::out);
    classesFile << "ID, Name, TeacherID\n";
    for (Classes& c : allClasses) {

        if (c.id == id) {
            c.teacherID = teacherID;
        }
        classesFile << std::to_string(c.id) << "," << c.name << "," << c.teacherID << "\n";

    }
    classesFile.close();

    return classes.getOne(id);
}


bool Classes::deleteClass(int id) {

    Classes classes;

    std::vector<Classes> allClasses = classes.getAll();

    classesFile.open("classes.csv", std::ios::out);
    classesFile << "ID, Name, TeacherID\n";
    for (Classes& c : allClasses) {

        if (c.id != id) {
            classesFile << std::to_string(c.id) << "," << c.name << "," << c.teacherID << "\n";
        }

    }
    classesFile.close();

    return true;

}