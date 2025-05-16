# refactoredStudentProcessor
This is an assignment based on the 2 week assignment that I had to do in my first year of computer science.

**Problem Statement**

You are provided with a file named input file.txt that contains students’ marks in the following
format:
studentid, course_code, test1, test2, test3, exam
Each line represents marks for a single student in one course. The presented file (input file.txt)
contains marks in raw form. It follows then that data in this format is not useful as it lacks insights
to assist in the interpretation of student performance in the class.

**Note:** You cannot use structs, arrays or vectors. Functions were forbidden for now, but the ban was lifted.

**INPUTS**

input file.txt, courseCode, studentID, test1, test2, test3, exam

**PROCESSING**
1. Open the input file.txt for READ as inputFile
2. Create the output.txt for WRITE as outputFile
3. IF inputFile cannot be read OR outputFile cannot be created THEN DISPLAY an error message and terminate the program with an exit failure.
4. Create a variable called skipHeader and READ a line from the inputFile
5. SET the following variables:
   minimumFinalMark to 100
   maximumFinalMark to 0
   minimumStudentID to 0
   maximumStudentID to 0

6. WHILE the inputFile has records DO
  READ studentID, courseCode, test1, test2, test3, exam FROM inputFile
  6.1 SET the following variables:
   testAverage to (test1 + test2 + test3)/3.0
   final mark to (0.4*testAverage)+(0.6*exam)
   nonDecimalFinalMark to finalMark
   rounder to finalMark - nonDecimalFinalMark

    6.2 IF rounder is greater than or equal to 0.5 THEN
         SET finalMark to nonDecimalFinalMark + 1
         ELSE
         SET finalMark to finalMark - rounder
       END IF

   6.3 SET maximumMark to test 1
       IF test 2 is greater than maximumMark THEN
         SET maximumMark to test2
       END IF
       IF test 3 is greater than maximumMark THEN
         SET maximumMark to test3
       END IF
       IF exam is greater than maximumMark THEN
         SET maximumMark to exam
       END IF

   6.4 SET minimumMark to test 1
       IF test 2 is less than minimumMark THEN
         SET minimumMark to test2
       END IF
       IF test 3 is less than minimumumMark THEN
         SET minimumMark to test3
       END IF
       IF exam is less than minimumMark THEN
         SET minimumMark to exam
       END IF

   6.5 IF finalMark is greater than maximumFinalMark THEN
       SET maximumFinalMark to finalMark
       SET maximumStudentID to studentID
       END IF

   6.6 IF finalMark is less than minimumnFinalMark THEN
       SET minimumFinalMark to finalMark
       SET minimumStudentID to studentID
       END IF
   
   6.7 IF finalMark is greater than or equal to 80 THEN
       SET grade to 'A'
       ELSE IF finalMark is greater than or equal to 70 THEN
       SET grade to 'B'
       ELSE IF finalMark is greater than or equal to 60 THEN
       SET grade to 'C'
       ELSE IF finalMark is greater than or equal to 50 THEN
       SET grade to 'D'
       ELSE
       SET grade to 'F'
       END IF

   6.8 WRITE studentID, "Final:", finalMark(2 decimal places), "Min:", minimumMark, "Max:", maximumMark, "Grade:", grade TO outputFile

END WHILE

7. WRITE NEWLINE, "Class Summary:" TO outputFile
   
    7.1 WRITE "Highest Final Mark: ", maximumFinalMark, "(", maximumStudentID, ")" TO outputFile
  
    7.2 WRITE "Lowest Final Mark: ", minimumFinalMark, "(", minimumStudentID. ")" TO outputFile

9. CLOSE inputFile
    
    8.1 CLOSE outputFile 
11. Terminate program with an exit success


**Output**

output.txt

   
