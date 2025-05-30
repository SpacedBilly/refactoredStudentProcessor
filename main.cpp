#include "students.h"
#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    //Open the input and output files
    std::ifstream inputFile("input file.txt");
    std::ofstream outputFile("output.txt");

    //check if the input or output files can be read or written
    if(!inputFile)
    {
        std::cerr << "Error reading from the input file!" << '\n';
        return 1;
    }

    if(!outputFile)
    {
        std::cerr << "Error creating the output file!" << '\n';
        return 1;
    }
    //skip the header line in the input file
    std::string headerSkip;
    getline(inputFile, headerSkip);
    processStudents(inputFile, outputFile);

    return 0;
}

