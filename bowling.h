/******************************************************************************
 * bowling.h
 *
 * This file contains prototypes and definitions used in the bowling function.  
 * Include this file if you need the functionality provided by Bowling.c
 *
 * Author:        Jeffrey Rolland
 * Creation Date: 11/12/2004
 * Modifications: 12/01/2004 - Rewrote to have #define properly stated as null 
 *							   definition
 *				  12/06/2004 - Capitalized functions per style requirements
 *          *****************************************************************************/

/******************************************************************************
 *
 * Note that the "includes guards" technique is incorporated into all 
 * (non-system) header files, to eliminate the need to be concerned about 
 * multiple inclusions of a given header and unneccessary program overhead.
 * 
******************************************************************************/

#ifndef BOWLING_H

	#define BOWLING_H   /* Null definition */
        
	/***************************************************************************
	*
	* Function Prototypes
	*
	***************************************************************************/

	void Bowling(void);
	int GetBall(int ball);
	void ComputeScore(int *score, int ball1fm2, int ball2fm2, int 
					  ball1fm1, int ball2fm1, int ball1, int ball2, 
					  int ball3, int frame);
	void PrintScore(int *score);
		
	/***************************************************************************
	*
	* Literal Definitions
	*
    ***************************************************************************/
	
	#define TRUE 1
	#define FALSE 0
	
#endif