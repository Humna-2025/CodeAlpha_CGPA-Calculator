#include <iostream>
using namespace std;

class Course
{
public:
 float grade;
 int creditHours;

 void inputCourseData(int courseNumber)
 {
 cout << "Enter grade for course " << courseNumber << ": ";
 cin >> grade;
 cout << "Enter credit hours for course " << courseNumber << ": ";
 cin >> creditHours;
 }

 float getGradePoints()
 {
 return grade * creditHours;
 }
};

class Student
{
private:
 Course courses[100];
 int numberOfCourses;
 float totalGradePoints;
 int totalCreditHours;

public:
 void inputCourses()
 {
 cout << "Enter number of courses: ";
 cin >> numberOfCourses;

 totalGradePoints = 0;
 totalCreditHours = 0;

 for (int i = 0; i < numberOfCourses; ++i)
 {
 cout << endl
 << "--- Course " << i + 1 << " ---" << endl;
 courses[i].inputCourseData(i + 1);
 totalGradePoints += courses[i].getGradePoints();
 totalCreditHours += courses[i].creditHours;
 }
 }

 void displayCoursesAndCGPA()
 {
 cout << endl
 << "====== Course Details ======" << endl;
 for (int i = 0; i < numberOfCourses; ++i)
 {
 cout << "Course " << i + 1
 << " - Grade: " << courses[i].grade
 << ", Credit Hours: " << courses[i].creditHours
 << ", Grade Points: " << courses[i].getGradePoints()
 << endl;
 }

 float gpa = totalGradePoints / totalCreditHours;

 cout << endl
 << "Total Credit Hours: " << totalCreditHours << endl;
 cout << "Total Grade Points: " << totalGradePoints << endl;
 cout << "Semester GPA (CGPA): " << gpa << endl;
 }
};

int main()
{
 Student student;
 student.inputCourses();
 student.displayCoursesAndCGPA();

 return 0;
}
