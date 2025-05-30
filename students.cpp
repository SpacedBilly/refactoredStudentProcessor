#include "students.h"
#include <iomanip>

float getTestAverage(int test1, int test2, int test3)
{
    return (test1+test2+test3)/3.0;
}

float getFinalMark(float testAverage, int exam)
{
    return (testAverage*0.4) + (exam*0.6);
}

int getMinimumMark(int test1, int test2, int test3, int exam)
{
    int minimum = test1;
    if(test2 < minimum)
        minimum = test2;
    if(test3 < minimum)
        minimum = test3;
    if(exam < minimum)
        minimum = exam;
    return minimum;
}

int getMaximumMark(int test1, int test2, int test3, int exam)
{
    int maximum = test1;
    if(test2 > maximum)
        maximum = test2;
    if(test3 > maximum)
        maximum = test3;
    if(exam > maximum)
        maximum = exam;
    return maximum;
}

float rounder(float mark)
{
    int nonDecimalMark = mark;
    float decimalPlace = mark - nonDecimalMark;
    if(decimalPlace >= 0.5)
        return nonDecimalMark + 1;
    else
        return mark - decimalPlace;
}

char assignGrade(float finalMark)
{
    if(finalMark >= 80)
        return 'A';
    else if(finalMark >= 70)
        return 'B';
    else if(finalMark >= 60)
        return 'C';
    else if(finalMark >= 50)
        return 'D';
    else
        return 'F';
}

void writeStudentResult(std::ofstream &outputFile, int studentID, float finalMark, int minimumMark, int maximumMark, char grade)
{
    //write this to the output file
    outputFile << studentID << " Final: " << std::fixed << std::setprecision(2)  << finalMark << " Min: " << minimumMark << " Max:" <<std::setw(3)<< maximumMark << " Grade: "  << grade << '\n'; 
}

void writeClassSummary(std::ofstream &outputFile, float maximumFinalMark, int maximumStudentID, float minimumFinalMark, int minimumStudentID)
{
    //this will be written after the write student function is used.
    outputFile << "\nClass Summary:\n";
    outputFile << "Highest Final Mark: " << maximumFinalMark << "(Student ID: " << std::fixed << std::setprecision(2)<< maximumStudentID << ")" << '\n';
    outputFile << "Lowest Final Mark: " << minimumFinalMark << "(Student ID: " << minimumStudentID << ")" << '\n'; 

}

void processStudents(std::ifstream &inputFile, std::ofstream &outputFile)
{
    int studentID = 0, test1 = 0, test2 = 0, test3 = 0, exam = 0, minimumMark = 0, maximumMark = 0;
    std::string courseCode;
    float finalMark = 0.0f, testAverage = 0.0f, minimumFinalMark = 100.0f, maximumFinalMark = 0.0f;
    char grade = ' ';
    int minimumStudentID = 0, maximumStudentID = 0;

    while(inputFile >> studentID >> courseCode >> test1 >> test2 >> test3 >> exam)
    {
        //get the testAverage, finalMark and round the final Mark
        testAverage = getTestAverage(test1, test2, test3);
        finalMark = getFinalMark(testAverage, exam);
        finalMark = rounder(finalMark);

        minimumMark = getMinimumMark(test1, test2, test3, exam);
        maximumMark = getMaximumMark(test1, test2, test3, exam);
        grade = assignGrade(finalMark);
        
        if(finalMark < minimumFinalMark)
        {
            minimumFinalMark = finalMark;
            minimumStudentID = studentID;
        }
        if(finalMark > maximumFinalMark)
        {
            maximumFinalMark = finalMark;
            maximumStudentID = studentID;
        }
        writeStudentResult(outputFile, studentID, finalMark, minimumMark, maximumMark, grade);
    }
    writeClassSummary(outputFile, maximumFinalMark, maximumStudentID, minimumFinalMark, minimumStudentID);

}
