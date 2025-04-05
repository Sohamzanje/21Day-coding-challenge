#include <iostream>
#include <string>

using namespace std;
class University {
private:
    static string universityName;  // Static variable to store university name

public:
    static void changeUniversityName(const string& name) {
        universityName = name;
    }

    void getUniversityDetails() const {
        cout << "University Name: " << universityName << endl;
    }

    University() {
        universityName = "XYZ University";
    }
};

string University::universityName = "XYZ University";

class Student {
private:
    int studentID;
    string studentName;
    string course;
    static int totalStudents;  // Static variable to keep track of the total number of students

public:
    const int admissionYear;  // Final variable for admission year (once assigned, it cannot be changed)

    Student(int id, const string& name, const string& course, int year)
        : studentID(id), studentName(name), course(course), admissionYear(year) {
        totalStudents++;  // Increment the total number of students whenever a new student is created
    }

    static int getTotalStudents() {
        return totalStudents;
    }

    void displayStudentDetails() const {
        cout << "Student ID: " << studentID << endl;
        cout << "Student Name: " << studentName << endl;
        cout << "Course: " << course << endl;
        cout << "Admission Year: " << admissionYear << endl;
    }
};

int Student::totalStudents = 0;

int main() {
    University u1;
    u1.getUniversityDetails();  // Display the initial university name

    University::changeUniversityName("ABC University");
    u1.getUniversityDetails();  // Display the updated university name

    Student s1(101, "Soham", "Computer Science", 2020);
    Student s2(102, "Swapnil", "Mechanical Engineering", 2021);

    cout << endl;
    s1.displayStudentDetails();
    cout << endl;
    s2.displayStudentDetails();

    cout << "\nTotal Students: " << Student::getTotalStudents() << endl;

    return 0;
}
