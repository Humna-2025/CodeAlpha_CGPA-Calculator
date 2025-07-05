# CodeAlpha_CGPA-Calculator
📄 Code Overview
This program is a Semester GPA (CGPA) Calculator using Object-Oriented Programming (OOP) concepts like classes, encapsulation, and arrays of objects.

It takes a student's courses, their grades, and credit hours, calculates grade points for each course, then computes the total GPA (CGPA).

🔷 Classes and Their Responsibilities
1️⃣ Course Class
Represents a single course.

Data Members:

grade — The grade (e.g., 3.0, 4.0) obtained in the course.

creditHours — Credit hours of the course.

Member Functions:

inputCourseData(int) — Prompts user to enter grade and creditHours for this course.

getGradePoints() — Returns grade × creditHours, which are the grade points for this course.

2️⃣ Student Class
Represents the student and all their courses.

Data Members:

courses[100] — Array of Course objects (supports up to 100 courses).

numberOfCourses — Number of courses taken.

totalGradePoints — Sum of all grade points.

totalCreditHours — Sum of all credit hours.

Member Functions:

inputCourses()

Asks how many courses the student took.

For each course, calls inputCourseData() of the corresponding Course object.

Accumulates total grade points and credit hours.

displayCoursesAndCGPA()

Displays details of each course: grade, credit hours, grade points.

Calculates and displays the CGPA:

CGPA
=
total grade points
total credit hours
CGPA= 
total credit hours
total grade points
​
 
🔷 main() Function
Creates a Student object.

Calls inputCourses() to input data.

Calls displayCoursesAndCGPA() to show all results.

🧹 Concepts Used
✅ Object-Oriented Programming (OOP)
✅ Encapsulation (data and methods in classes)
✅ Array of objects
✅ Input/output handling
✅ Simple arithmetic to calculate GPA
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
                   cout << endl << "--- Course " << i + 1 << " ---" << endl;
                   courses[i].inputCourseData(i + 1);
                   totalGradePoints += courses[i].getGradePoints();
                   totalCreditHours += courses[i].creditHours;
               }
               }

                  void displayCoursesAndCGPA()
               {
                  cout << endl<< "====== Course Details ======" << endl;
                  for (int i = 0; i < numberOfCourses; ++i)
               {
                  cout<<"Course "<<i + 1<<" - Grade: "<<courses[i].grade<<", Credit Hours: "<<courses[i].creditHours<<", Grade Points: "<<courses[i].getGradePoints()<<endl;
               }

                 float gpa = totalGradePoints / totalCreditHours;

                 cout<<endl<<"Total Credit Hours: "<<totalCreditHours<<endl;
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
