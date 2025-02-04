/******************************************************************************
 * myInfo.c
 *
 * This file contains the functionality allowing a code module to identify
 * itself.
 *
 * Author:        Jeffrey Rolland
 * Creation Date: 02/08/2004
 * Modifications: 02/09/2004 - Moved #define statements into myInfo.h
 *                11/06/2004 - Changed assignmentNumber to a string
 *	 			  12/06/2004 - Capitalized functions per style requirements
 *         ******************************************************************************/

/******************************************************************************
 * header inclusions
 * 
 * Note that the "includes guards" technique is incorporated into all 
 * (non-system) header files, to eliminate the need to be concerned about 
 * multiple inclusions of a given header and unneccessary program overhead.
 * 
******************************************************************************/

#include <stdio.h>
#include "myInfo.h"

/******************************************************************************
 * void myInfo(int assignmentNumber, char *compileDate, char *compileTime)
 *
 * This function display information about the program. The student's name, the 
 * the course information and instructor's name are literal definitions, but 
 * the assignment number and compilation date-and-time card are passed to it as 
 * parameters from the calling function. (The date and time are usually invoked 
 * from the __DATE__ and __TIME__ macros in the function call.)
 * 
******************************************************************************/

void MyInfo(char *assignmentNumber, char *compileDate, char *compileTime)
{
	printf("Name:\t \t %s \n", STUDENT_NAME);
	printf("Course:\t \t %s \n", COURSE_NAME);
	printf("Instructor:\t %s \n", INSTRUCTOR_NAME);
	printf("Assignment:\t %s\n", assignmentNumber);
	printf("Compiled on:\t %s %s\n\n", compileDate, compileTime);
}