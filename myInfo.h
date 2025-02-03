/*******************************************************************************
 * myInfo.h
 *
 * This file contains prototypes and definitions used in code module 
 * identification.  Include this file if you need the functionality provided by 
 * myInfo.c
 *
 * Author:        Jeffrey Rolland
 * Creation Date: 02/08/2004
 * Modifications: 02/09/2004 - Moved define statements from myInfo.c and 
 *							   placed "include guard" headers around them
 *				  02/11/2004 - Removed multiple "include guards" and enclosed 
 * 							   entire header inside single #define
 *				  12/01/2004 - Rewrote to have #define properly stated as null 
 *							   definition
 * 				  12/06/2004 - Capitalized functions per style requirements
 *          *******************************************************************************/

/*******************************************************************************
 *
 * Note that the "includes guards" technique is incorporated into all 
 * (non-system) header files, to eliminate the need to be concerned about 
 * multiple inclusions of a given header and unneccessary program overhead.
 * 
*******************************************************************************/

#ifndef MYINFO_H

	#define MYINFO_H   /* Null definition */
        
	/***************************************************************************
	 *
	 * Function Prototypes
	 *
	***************************************************************************/

	void MyInfo(char *assignmentNumber, char *compileDate, char 
				*compileTime);
		
	/***************************************************************************
	 *
	 * Literal Declarations
	 *
	***************************************************************************/

	#define STUDENT_NAME "Jeffrey Rolland"
	#define COURSE_NAME "CIS 106 - Programming in C"
	#define INSTRUCTOR_NAME "Judith Ligocki"
	
#endif