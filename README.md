

![image](https://user-images.githubusercontent.com/100541934/218433301-e8e8e772-82d0-4fe0-9b6a-0c2bd77ab4d5.png)
![image](https://user-images.githubusercontent.com/100541934/218433486-12383d27-4b6e-4287-b891-8c60838f9d52.png)
![image](https://user-images.githubusercontent.com/100541934/218433641-b34eea63-3bbd-4924-870a-9770b9dda916.png)


Style Guide
1. Every user is assigned to one of the classes (Admin, Teacher or Parents)
2. The three classes inherit their superclass (Class users)
3. Admin, Teachers, or Parents classes use vector array to enable remove and create features
4. Each time a new user is added, all fields of users (e.g. name, email address) are initialized using the User() constructor.
5. Admins get access to all classes and structs through functions to add, edit, remove or create new objects (instance).
6. Teachers get access to structs (students and classes) in order to view or input record
7. Parents get access to only view the grade record of their child.
8. all input data (new,edit,remove or add) will be saved to a CSV file.
9. Create a session by logging in as a new user
10. Admin creates new users with one time password
11. First time users will change password on login


# School Information System
**Data Classes**
 - [Users](#users)
 - [Students](#students)
 - [Classes](#classes)
 - [Enrollments](#enrollments)
 - [Grades](#grades)

# Users
Users class handles user accounts including logging into the application.

Members:
- id (int)
- name (string)
- userType (int)
- email (string)
- password (string)
- passwordSet (string)

Methods:

    getAll() - Returns a vector of Users
    getOne(int id) - Returns a user of Users matching id
    newUser(string name, int userType, string email, string password) - Returns true on success
    editName(int id, string name) - Returns edited user of Users matching id
    editEmail(int id, string email) - Returns edited user of Users matching id
    editPassword(int id, string password) - Returns edited user of Users matching id
    deleteUser(int id) - Returns true on success
    login() - Returns a user of Users matching logged in user

**Use Examples:**

***Create instance***

    Users users;
    
***New user***

    users.newUser("Ted Bundy", 1, "tbundy@school.co.nz", "abc123");
    
***List all users***

    std::vector<Users> allUsers = users.getAll();

    for (const Users& u : allUsers) {
        std::cout << u.name << " " << u.email << "\n";
    }
    
***Output name from user id***

    Users foundUser = users.getOne(1);
    std::cout << foundUser.name << "\n";

***Edit users name and output new name***

    Users edited = users.editName(1, "New Name");
    std::cout << edited.name;
    
***Edit user email and password***

    users.editEmail(1, "newemail@school.co.nz");
    users.editPassword(1, "newpass");

***Delete user***

    users.deleteUser(1);

***User login and output userType***

    Users loggedInUser = users.login();
    std::cout << loggedInUser.userType;

# Students
Students class handles the management of students, does not include class enrollments or grades.

Members:
- id (int)
- name (string)
- parentID (int)

Methods:

    getAll() - Returns a vector of Students
    getOne(int id) - Returns a student of Students matching id
    newStudent(string name, int parentID) - Returns true on success
    editName(int id, string name) - Returns edited user of Users matching id
    editParent(int id, int parentID) - Returns edited student of Students matching id
    deleteStudent(int id) - Returns true on success

**Use Examples:**

***Create instance***

    Students students;
    
***New student***

    students.newStudent("Billy Bundy", 1);
    
***List all students***

    std::vector<Students> allStudents = students.getAll();

    for (const Students& s : allStudents) {
        std::cout << s.name << "\n";
    }
    
***Output name from student id***

    Users foundStudent = students.getOne(1);
    std::cout << foundStudent.name << "\n";

***Edit student name and output new name***

    Students edited = students.editName(1, "New Name");
    std::cout << edited.name;
    
***Edit students parentID***

    students.editParent(1, 3);

***Delete student***

    students.deleteStudent(1);

# Classes

Classes class handles the management of classes, does not include enrollments or grades.

# Enrollments

Enrollments class handles the management of class enrollments.

Members:
- studentID (int)
- classID (int)

Methods:

    getAll() - Returns a vector of Enrollments
    getAllByStudent(int studentID) - Returns a vector of Enrollments
    getAllByClass(int classID) - Returns a vector of Enrollments
    newEnrollment(int studentID, int classID) - Returns true on success
    deleteEnrollment(int studentID, int classID) - Returns true on success

**Use Examples:**

***Create instance***

    Enrollments enrollments;
    
***New enrollment***

    enrollments.newEnrollment(1, 1);
    
***List all students enrolled in a class***

    std::vector<Enrollments> classEnrollments = enrollments.getAllByClass(1);

    for (const Enrollments& e : classEnrollments) {
        // outputs student names for class
        std::cout << students.getOne(e.studentID).name << "\n";
        
***List all classes a student is enrolled in***

    std::vector<Enrollments> studentEnrollments = enrollments.getAllByStudent(1);

    for (const Enrollments& e : studentEnrollments) {
        // outputs class names for student
        std::cout << classes.getOne(e.classID).name << "\n";

***Delete an enrollment***

    enrolments.deleteEnrolment(1, 1);


# Grades

Grades class handles the management of student grades for each class.

Members:
- studentID (int)
- classID (int)
- grade (string)

Methods:

    getAll() - Returns a vector of Enrollments
    getAllByStudent(int studentID) - Returns a vector of Enrollments
    getAllByClass(int classID) - Returns a vector of Enrollments
    newGrade(int studentID, int classID, string grade) - Returns true on success
    deleteGrade(int studentID, int classID) - Returns true on success

**Use Examples:**

***Create instance***

    Grades grades;
    
***New grade***

    grades.newGrade(1, 1, "A+");
    
***List all grades of students in a class***

    std::vector<Grades> classGrades = grades.getAllByClass(1);

    for (const Grades& g : classGrades) {
        std::cout << students.getOne(g.studentID).name << " Grade: " << g.grade << "\n";
    }
        
***List all class grades of a student***

    std::vector<Grades> studentGrades = grades.getAllByStudent(1);

    for (const Grades& g : studentGrades) {
        // outputs class names and grades for student
        std::cout << classes.getOne(g.classID).name << " Grade: " << g.grade << "\n";
    }

***Delete a grade***

    grades.deleteGrade(1, 1);
