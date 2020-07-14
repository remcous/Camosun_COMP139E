/*
COMP139E
Lab 2 - Computing Grades
grades.cpp - A program designed to take user input for the mark and weight of a series
of graded coursework summing to a total weight of 100%, and printing to the console the
average grade in terms of both percentage and a Camosun College letter grade.

By: Remi Coussement
C0450402
*/

#include <iostream>

using namespace std;

/**
 * A reusable function for getting validated in-range numbers.
 * Repeatedly asks for the value if an out-of-range number gets entered
 *
 * @param prompt A string such as "Enter the mark"
 * @param number A pointer to the number we are trying to read
 * @param min The minimum permissible value
 * @param max The maximum permissible value  
 *
 * @return true if the input contains only numeric characters, false otherwise
 */
bool getValidNumber(const char *prompt, double *value, const double min, const double max);

/**
* A function to convert a weighted average mark to a Camosun College letter grade
*
* @param weighted_average The weighted average of marks for a course
*/
void print_grade(const double weighted_average);

int main(){
    const double min_mark = 0.0, max_mark = 100.0;
    const double min_weight = 1.0, max_weight = 50.0;
    double mark, weight, total_mark=0.0, total_weight=0.0;
    bool get_mark = true;

    // Prints the instructions for the program to the console
    cout << "This program computes a letter grade from a weighted sum of marks" << endl
        << "For marks, minimum allowable value is 0, maximum is 100" << endl
        << "For weights, minimum allowable value is 1, maximum is 50" << endl
        << "The weights must total 100%" << endl
        << "Enter a non-number (such as 'q') to terminate your list of marks\n\n"; 

    // Collect marks and weights from the user, using error handling to ensure only valid values are accepted
    while(get_mark){
        get_mark = getValidNumber("Enter a mark in percent: ", &mark, min_mark, max_mark);
        if(get_mark){
            get_mark = getValidNumber("       Enter the weight: ", &weight, min_weight, max_weight);
        }

        // Adds the mark and weight to the running total for the mark and weight
        if(get_mark){
            total_mark += mark * weight / 100;
            total_weight += weight;
        }
    }

    // Ensures that the cummulative weight of the grades entered is 100.0% +- 0.1%
    if(total_weight < 99.9 || total_weight > 100.1){
        cout << "Weights did not add up to 100%. Try again." << endl;
        return 0;
    }

    print_grade(total_mark);

    return 0;
}

bool getValidNumber(const char *prompt, double *value, const double min, const double max){
    // Gets user input and ensures that it is a valid number which is between the min and max values
    do{
        cout << prompt;
        cin >> *value;
        if (cin.good() == false) {           // Invalid Input (not a number in this case)
            cin.clear();             // Clear the error flags
            cin.ignore(255, '\n');   // Throw away the line of input
            cout << "Input data terminated." << endl;           
            return false;
        }

        if(*value < min || *value > max){
            cout << "Number is out of range.\tTry again." << endl;
        }
    }while(*value < min || *value > max);

    return true;
}

void print_grade(const double weighted_average){
    string grade;

    // Determines the appropriate camosun letter grade based on the weighted_average
    if(weighted_average >= 90){
        grade = "A+";
    }
    else if(weighted_average >= 85){
        grade = "A";
    }
    else if(weighted_average >= 80){
        grade = "A-";
    }
    else if(weighted_average >= 77){
        grade = "B+";
    }
    else if(weighted_average >= 73){
        grade = "B";
    }
    else if(weighted_average >= 70){
        grade = "B-";
    }
    else if(weighted_average >= 65){
        grade = "C+";
    }
    else if(weighted_average >= 60){
        grade = "C";
    }
    else if(weighted_average >= 50){
        grade = "D";
    }
    else{
        grade = "F";
    }

    // Outputs the total mark and letter grade to the console
    cout << "Mark is " << weighted_average << " and grade is " << grade << endl;
}