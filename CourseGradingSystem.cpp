#include <iostream>
#include <iomanip>

// Declare the maximum amount of students, courses, and grades per student per course
const size_t gradesLength = 10;
const size_t coursesLength = 10;
const size_t studentsLength = 10;

// Predefined list of courses
std::string courses[coursesLength] = {
    "Math",
    "Physics",
    "Biology",
    "Chemistry"
};

// Predefined list of students
std::string students[studentsLength] = {
    "Aleksei Kovalev",
    "John Doe",
    "Mark Trio"
};

// Menu options
std::string options[] = {
    "Display all courses",
    "Display all students",
    "Display all grades of a student",
    "Display a student's grades within a course",
    "Display everyone's grades within a course",
    "Display all grades",
    "Add a new course",
    "Remove a course",
    "Add a new student",
    "Remove a student",
    "Calculate a student's GPA",
    "Calculate a course average",
    "Add a new grade"
};
const size_t optionsLength = sizeof(options)/sizeof(options[0]);

// Declare 3D grades array and initialize with 0s
double grades[studentsLength][coursesLength][gradesLength] = {0};

// Function prototype declarations
void displayArray(std::string[], size_t);
double calculateAverage(double[], size_t);
void displaySingleStudentGrades(std::string);
void displaySingleStudentGradesInCourse(std::string, std::string);
void displayEveryonesGradesInCourse(std::string);
void displayAllAverageGrades();
void addNewCourse(std::string);
void removeCourse(std::string);
void addNewStudent(std::string);
void removeStudent(std::string);
void calculateStudentGPA(std::string);
void calculateCourseAverage(std::string);
void addGrade(std::string, std::string, double);

// Main function
int main()
{
    // Print the greeting and all the options from the menu
    std::cout << "Course Grading System" << std::endl << std::endl;
    std::cout << "Enter the corresponding number to proceed with one of these options:" << std::endl << std::endl;
    
    // Go throught
    for (size_t i = 0; i < optionsLength; i++)
    {
        std::cout << i + 1 << ": " + options[i] << std::endl;
    }
    
    // Start the main loop of the program
    while (true)
    {
        // Let the user know they can exit the program by entering -1
        std::cout << std::endl << "Enter -1 at any point to exit, or 0 to show the options menu." << std::endl;
        
        // Ask the user to input the number corresponding to the desired option from the menu
        int chosenOption;
        // If the input is not an integer, let the user know the input is invalid
        if (!(std::cin >> chosenOption)) {
            std::cin.clear();
            std::cin.ignore();
            std::cout << std::endl << "Invalid option, please try again." << std::endl;
        }

        // Proceed with the needed functionality based on user's input
        if (chosenOption == -1) {
            // Leave the while loop by breaking
            std::cout << std::endl << "Thanks for using our program!" << std::endl;
            break;
        } else if (chosenOption == 0) {
            std::cout << std::endl << "Enter the corresponding number to proceed with one of these options:" << std::endl << std::endl;
            
            // Print the options menu again
            for (size_t i = 0; i < optionsLength; i++) {
                std::cout << i + 1 << ": " + options[i] << std::endl;
            }
        } else if (chosenOption == 1) {
            std::cout << std::endl << "These are all the available courses: " << std::endl;
            
            // Print out all elements of the course array
            displayArray(courses, coursesLength);
        } else if (chosenOption == 2) {
            std::cout << std::endl << "These are all the available students: " << std::endl;
            
            // Print out all elements of the student array
            displayArray(students, studentsLength);
        } else if (chosenOption == 3) {
            std::cout << std::endl << "Enter the student's full name: ";
            
            // Accept a full line input from the user as a string
            std::string studentName;
            std::getline(std::cin >> std::ws, studentName);
            
            std::cout << std::endl;
            
            // Use the entered line to find student with such name and display all their grades
            displaySingleStudentGrades(studentName);
        } else if (chosenOption == 4) {
            std::cout << std::endl << "Enter the student's full name: ";
            
            // Accept a full line input from the user as a string
            std::string studentName;
            std::getline(std::cin >> std::ws, studentName);
            
            std::cout << std::endl;
            
            std::cout << std::endl << "Enter the course name: ";
            
            // Accept a full line input from the user as a string
            std::string courseName;
            std::getline(std::cin >> std::ws, courseName);
            
            std::cout << std::endl;

            // Use the entered values as the names of the student and the course to look for, and display all the grades for that student in that course
            displaySingleStudentGradesInCourse(studentName, courseName);
        } else if (chosenOption == 5) {
            std::cout << std::endl << "Enter the course name: ";
            
            // Accept a full line input from the user as a string
            std::string courseName;
            std::getline(std::cin >> std::ws, courseName);
            
            std::cout << std::endl;

            // Use the entered value as the course name to look for and print the grades of all the students in that course
            displayEveryonesGradesInCourse(courseName);
        } else if (chosenOption == 6) {
            
            // Display all the average grades for each course of each student
            displayAllAverageGrades();
        } else if (chosenOption == 7) {
            std::cout << "Enter the new course name: ";
            
            // Accept a full line input from the user as a string
            std::string courseName;
            std::getline(std::cin >> std::ws, courseName);
            
            // Use the entered value as a new course name to add, if it does not already exist
            addNewCourse(courseName);
        } else if (chosenOption == 8) {
            std::cout << "Enter the name of the course to remove: ";
            
            // Accept a full line input from the user as a string
            std::string courseName;
            std::getline(std::cin >> std::ws, courseName);
            
            // Use the entered value as a course name to remove from the existing array
            removeCourse(courseName);
        } else if (chosenOption == 9) {
            std::cout << "Enter the new student's name: ";
            
            // Accept a full line input from the user as a string
            std::string studentName;
            std::getline(std::cin >> std::ws, studentName);
            
            // Use the entered value as a new student name to add, unless it already exists
            addNewStudent(studentName);
        } else if (chosenOption == 10) {
            std::cout << "Enter the student's name to remove: ";
            
            // Accept a full line input from the user as a string
            std::string studentName;
            std::getline(std::cin >> std::ws, studentName);
            
            // Use the entered value as a student name to remove from the existing array
            removeStudent(studentName);
        } else if (chosenOption == 11) {
            std::cout << "Enter the student's name: ";
            
            // Accept a full line input from the user as a string
            std::string studentName;
            std::getline(std::cin >> std::ws, studentName);
            
            // Use the entered value as a student name to calculate total average grade throughout all their courses
            calculateStudentGPA(studentName);
        } else if (chosenOption == 12) {
            std::cout << "Enter the course name: ";
            
            // Accept a full line input from the user as a string
            std::string courseName;
            std::getline(std::cin >> std::ws, courseName);
           
            // Use the entered value as a course name to calculate the total average grade for all students within the course
            calculateCourseAverage(courseName);
        } else if (chosenOption == 13) {
            std::string courseName;
            std::string studentName;
            double grade;
            bool courseExists = false, studentExists = false;

            std::cout << "Enter the course name: ";
            
            // Accept a full line input from the user as a string
            std::getline(std::cin >> std::ws, courseName);
            
            // Check if entered value exists in the course array
            for (int i = 0; i < coursesLength; i++) {
                if(courses[i] == courseName) {
                    courseExists = true;
                    break;
                }
            }
            
            // Let the user know if the course they are looking for does not exist
            if(!courseExists) {
                std::cout << "No such course, please try again!" << std::endl;
                continue;
            }
            
            std::cout << "Enter the student's name: ";
            
            // Accept a full line input from the user as a string
            std::getline(std::cin >> std::ws, studentName);
            
            // Check if entered value exists in the students array
            for (int i = 0; i < studentsLength; i++) {
                if(students[i] == studentName) {
                    studentExists = true;
                    break;
                }
            }
            
            // Let the user know if the student they are looking for does not exist
            if(!studentExists) {
                std::cout << "No such student, please try again!" << std::endl;
                continue;
            }
            
            std::cout << "Enter the grade to add: ";
            
            // Accept a number input from the user
            if(std::cin >> grade) {
                // Make sure the entered value is between 0 and 100
                if(grade > 0 && grade <= 100) {
                    // Add the entered grade value to the respective course for the respective student
                    addGrade(studentName, courseName, grade);
                } else {
                    // Let the user know if the grade does not fall in proper bounds
                    std::cout << "Grade must be between 1 and 100" << std::endl;
                }
            } else {
                // Let the user know if the entered value is invalid (not a number)
                std::cout << "Invalid grade input, please try again!" << std::endl;
            }
        } else {
            // Let the user know their input is invalid for the options menu
            std::cout << "No such option, try again please!" << std::endl;
        }
    }

    return 0;
}

// Utility function to display a one-dimensional array to the user
void displayArray(std::string arr[], size_t arrLength) {
    for (size_t i = 0; i < arrLength; i++) {
        // Ignore empty elements
        if(!arr[i].empty()) std::cout << arr[i] << std::endl;
    }
}

// Search for a specific student's grades and print them to the user
void displaySingleStudentGrades(std::string studentName) {
    int studentIndex = -1;
   
    // Check if student exists
    for (int i = 0; i < studentsLength; i++) {
        if(students[i] == studentName) {
            studentIndex = i;
            break;
        }
    }
    
    if(studentIndex >= 0) {
        for (int j = 0; j < coursesLength; j++) {
            std::string currentCourse = courses[j];
            
            // Skip through empty values
            if(currentCourse.empty()) continue;
            
            std::cout << currentCourse << ": " << std::endl;
            
            for (int k = 0; k < gradesLength; k++) {
                double currentGrade = grades[studentIndex][j][k];
                
                std::cout << currentGrade << ", ";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "No such student, try again please :)" << std::endl;
    }
}

// Search for a specific student's grades in a specific course and print them out to the user
void displaySingleStudentGradesInCourse(std::string studentName, std::string courseName) {
    int studentIndex = -1;
    
    // Check if student exists and save the index if so
    for (int i = 0; i < studentsLength; i++) {
        if(students[i] == studentName) {
            studentIndex = i;
            break;
        }
    }
    
    int courseIndex = -1;
    
    // Check if course exists and save the index if so
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i] == courseName) {
            courseIndex = i;
            break;
        }
    }

    // Let the user know the student does not exist
    if(studentIndex == -1) {
        std::cout << "No such student, try again please :)" << std::endl;
        return;
    }
    
    // Let the user know the course does not exist
    if(courseIndex == -1) {
        std::cout << "No such course, try again please :)" << std::endl;
        return;
    }

    std::cout << "These are all the grades for " << studentName << " in " << courseName << ": " << std::endl;
    for (int k = 0; k < gradesLength; k++) {
        double currentGrade = grades[studentIndex][courseIndex][k];
        
        std::cout << currentGrade << ", ";
    }
    std::cout << std::endl;
}

// Utility function to calculate the average of numbers in a one-dimensional array
double calculateAverage(double arr[], size_t arrLength) {
    double sum = 0, average = 0;
    
    for (int i = 0; i < arrLength; i++) {
        // Ignore 0s for calculating the average
        if(arr[i] == 0) continue;
        sum += arr[i];
    }
    
    average = sum / arrLength;
    
    return average;
}

// Function that accepts a course name and displays all the student's grades in that course in order
void displayEveryonesGradesInCourse(std::string courseName) {
    bool courseExists = false;
    int courseIndex = -1;
    
    // Check if course exists
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i] == courseName) {
            courseExists = true;
            courseIndex = i;
            break;
        }
    }
    
    // Let the user know the course does not exist
    if(!courseExists) {
        std::cout << "No such course!" << std::endl;
        return;
    }
    
    std::cout << "Everyone's grades for " << courseName << ": " << std::endl;
    for (int i = 0; i < studentsLength; i++) {
        // Skip through empty elements
        if(students[i].empty()) continue;
        
        std::cout << students[i] << ": " << std::endl;
        for (int j = 0; j < gradesLength; j++) {
            std::cout << grades[i][courseIndex][j] << ", ";
        }
        std::cout << std::endl;
    }
}

// Function that displays all the average grades of each student for each course in a table
void displayAllAverageGrades() {
    // Set the limit on the amount of characters that can be printed for each column of the table, so that everything is evenly spaced
    const size_t printSize = 10;
    std::string currentStudent = "";
    
    std::cout << std::setw(printSize) << "\t";
    for (int i = 0; i < studentsLength; i++) {
        currentStudent = students[i].substr(0, printSize - 1);
        if(currentStudent.empty()) continue;

        std::cout << std::setw(printSize + 2) << currentStudent;
    }
    
    std::cout << std::endl;
    
    for (int i = 0; i < coursesLength; i++) {
        std::cout << std::setw(printSize);
        std::string currentCourse = courses[i].substr(0, printSize - 1);
        
        if(currentCourse.empty()) continue;
        
        std::cout << currentCourse;
        for (int j = 0; j < studentsLength; j++) {
            currentStudent = students[j].substr(0, printSize - 1);
            if(currentStudent.empty()) continue;
            double currentAverageGrade = calculateAverage(grades[j][i], gradesLength);
           
            std::cout << std::setw(printSize + 2) << currentAverageGrade;
        }
        std::cout << std::endl;
    }
}

// Function that accepts a course name and adds it to the course array, unless it already exists
void addNewCourse(std::string courseName) {
    
    // Check if such course already exists
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i] == courseName) {
            std::cout << "This course already exists!" << std::endl;
            return;
        }
    }
    
    // Add the new course into the first empty spot in the array
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i].empty()) {
            courses[i] = courseName;
            std::cout << "Course successfully added!" << std::endl;
            return;
        }
    }
    
    // Let the user know that there was not any space for a new course
    std::cout << "Couldn't add another course because the limit for courses was reached." << std::endl;
}

// Function that accepts a course name and deletes it from the course array if it exists
void removeCourse(std::string courseName) {
    int courseIndex = -1;
    
    // Check if the course exists
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i] == courseName) {
            courseIndex = i;
            break;
        }
    }
        
    // Let the user know there is no such course
    if(courseIndex == -1) {
        std::cout << "No such course!" << std::endl;
        return;
    }
    
    // Set the course to empty string
    courses[courseIndex] = "";
    std::cout << "Successfully removed " << courseName << std::endl;
}

// Function that accepts a student name and adds it to the students array, unless it already exists
void addNewStudent(std::string studentName) {
    
    // Check if student already exists
    for (int i = 0; i < studentsLength; i++) {
        if(students[i] == studentName) {
            std::cout << "This student already exists!" << std::endl;
            return;
        }
    }
    
    // Add the student to the first empty spot in the array
    for (int i = 0; i < studentsLength; i++) {
        if(students[i].empty()) {
            students[i] = studentName;
            std::cout << "Student successfully added!" << std::endl;
            return;
        }
    }
    
    // Let the user know there was not enough space for a new student
    std::cout << "Couldn't add another student because the limit for students was reached." << std::endl;
}

// Function that accepts a student name and deletes it from the student array if it exists
void removeStudent(std::string studentName) {
    int studentIndex = -1;
    
    // Check if student exists
    for (int i = 0; i < studentsLength; i++) {
        if(students[i] == studentName) {
            studentIndex = i;
            break;
        }
    }
        
    // Let the user know if the student does not exist
    if(studentIndex == -1) {
        std::cout << "No such student!" << std::endl;
        return;
    }
    
    // Set the student's name to an empty string
    students[studentIndex] = "";
    std::cout << "Successfully removed " << studentName << std::endl;
}

// Function that takes the name of the student and the name of the course, and the value of the grade to add
void addGrade(std::string studentName, std::string courseName, double grade) {
    bool studentExists = false;
    bool courseExists = false;
    int studentIndex = -1;
    int courseIndex = -1;

    // Check if student exists
    for (int i = 0; i < studentsLength; i++) {
        if(students[i] == studentName) {
            studentExists = true;
            studentIndex = i;
            break;
        }
    }
    
    // Check if course exists
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i] == courseName) {
            courseExists = true;
            courseIndex = i;
            break;
        }
    }

    // Let the user know if such student does not exist
    if(!studentExists) {
        std::cout << "No such student!" << std::endl;
    }
    
    // Let the user know if such course does not exist
    if(!courseExists) {
        std::cout << "No such course!" << std::endl;
    }
    
    // Add the grade to the first empty spot (0) in the respective grades array
    for (int i = 0; i < gradesLength; i++) {
        if(grades[studentIndex][courseIndex][i] == 0) {
            grades[studentIndex][courseIndex][i] = grade;
            std::cout << "Grade successfully added" << std::endl;
            return;
        }
    }
    
    // Let the user know there wasn't a free space for the grade and ask them if they'd like to replace an existing grade instead
    std::cout << "No empty space for a grade, would you like to replace an existing grade? (y/n)" << std::endl;
    
    while(true) {
        char response;
        std::cin >> response;
        response = std::tolower(response);

        if (response == 'y') {
            double gradeToReplace = 0;
            
            // Ask the user which existing grade value they would like to replace
            std::cout << "Enter the grade value to replace: ";
            std::cin >> gradeToReplace;
            
            for (int i = 0; i < gradesLength; i++) {
                // Find such a value and replace it
                if(grades[studentIndex][courseIndex][i] == gradeToReplace) {
                    grades[studentIndex][courseIndex][i] = grade;
                    
                    std::cout << "Successfully replaced " << gradeToReplace << " with " << grade << std::endl;
                    return;
                } else {
                    std::cout << "No such grade in the list, please try again" << std::endl;
                }
            }
        } else if (response == 'n') {
            return;
        } else {
            std::cout << "Invalid input. Please enter 'y' or 'n'." << std::endl;
        }
    }
}

// Function that takes a student's name and calculates their average grade throughout all courses
void calculateStudentGPA(std::string studentName) {
    bool studentExists = false;
    int studentIndex = -1;
    
    // Check if student exists
    for (int i = 0; i < studentsLength; i++) {
        if(students[i] == studentName) {
            studentExists = true;
            studentIndex = i;
            break;
        }
    }
    
    // Let the user know if such student does not exist
    if(!studentExists) {
        std::cout << "No such student!" << std::endl;
        return;
    }
    
    double sumOfAllGrades = 0, GPA = 0;
    int numOfGrades = 0;
    
    // Go through the grades for each course the student has and accumulate their sum and count
    for (int i = 0; i < coursesLength; i++) {
        for (int j = 0; j < gradesLength; j++) {
            if(grades[studentIndex][i][j] == 0) continue;
            
            std::cout << grades[studentIndex][i][j] << " ";
            
            sumOfAllGrades += grades[studentIndex][i][j];
            numOfGrades++;
        }
    }
    
    // Let the user know the student does not have any grades more than 0 yet
    if(sumOfAllGrades == 0) {
        std::cout << studentName << " does not have any grades yet." << std::endl;
        return;
    }
    
    // Calcualte the students GPA by dividing the sum of their grades by their count
    GPA = sumOfAllGrades / numOfGrades;
    
    // Print out to the user the student's GPA
    std::cout << studentName << "'s average grade is " << GPA << std::endl;
}

// Function that takes a course name and calculates an average among all students of that course
void calculateCourseAverage(std::string courseName) {
    bool courseExists = false;
    int courseIndex = -1;
    
    // Check if the course exists
    for (int i = 0; i < coursesLength; i++) {
        if(courses[i] == courseName) {
            courseExists = true;
            courseIndex = i;
            break;
        }
    }
    
    // Let the user know the course does not exist
    if(!courseExists) {
        std::cout << "No such course!" << std::endl;
        return;
    }
    
    double numOfGrades = 0, sumOfGrades = 0, averageForCourse = 0;
    
    // Go through all the grades for each student within the course and accumulate their sum and their count
    for (int i = 0; i < studentsLength; i++) {
        for(int j = 0; j < gradesLength; j++) {
            if(grades[i][courseIndex][j] == 0) continue;
            
            sumOfGrades += grades[i][courseIndex][j];
            numOfGrades++;
        }
    }
    
    // Calculate the average by dividing the sum of all the grades by their count
    averageForCourse = sumOfGrades / numOfGrades;
    
    // Print out to the user the average for the course
    std::cout << "The average grade for " << courseName << " is " << averageForCourse << std::endl;
}

