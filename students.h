#ifndef STUDENTS_H
#define STUDENTS_H
#include <fstream>
float getTestAverage(int test1, int test2, int test3);
float getFinalMark(float testAverage, int exam);
int getMinimumMark(int test1, int test2, int test3, int exam);
int getMaximumMark(int test1, int test2, int test3, int exam);
float rounder(float mark);
char assignGrade(float finalMark);
void writeStudentResult(std::ofstream &outputFile, int studentID, float finalMark, int minimumMark, int maximumMark, char grade);
void writeClassSummary(std::ofstream &outputFile, float maximumFinalMark, int maximumStudentID, float minimumFinalMark, int minimumStudentID);
void processStudents(std::ifstream &inputFile, std::ofstream &outputFile);

#endif