/******************************************************************************
 * Bowling.c
 *
 * This file contains the functionality to compute bowling scores.
 *
 * Author:        Jeffrey Rolland
 * Creation Date: 11/12/2004
 * Modifications: 12/06/2004 - Capitalized functions per style requirements
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
#include "bowling.h"

/******************************************************************************
 * void Bowling(void)
 *
 * This function is the main driver for the bowling program. It gets the ball 
 * amounts then updates the scores vector and prints the scores.
 * 
******************************************************************************/

void Bowling(void)
{
	int ball1, ball2, ball3, ball1fm1, ball2fm1, ball1fm2, ball2fm2, frame, 
		score[10], total;
		
	ball1fm2 = 0;
	ball2fm2 = 0;
	ball1fm1 = 0;
	ball2fm1 = 0;	
	for(frame = 1; frame <= 10; frame++)
	{
		score[frame-1] = 0;
	}
	
	for(frame = 1; frame <= 10; frame++)
	{
		printf("Frame %d:\n", frame);
		
		/* mave balls from previous frames to previous frame variables */
		if(frame > 2)
		{
			ball1fm2 = ball1fm1;
			ball2fm2 = ball2fm1;
		}
		
		if(frame > 1)
		{
			ball1fm1 = ball1;
			ball2fm1 = ball2;
		}

		if(frame==1)
		{
			PrintScore(score);
		}
		
		if(frame < 10)
		{
			do
			{
				ball1 = GetBall(1);
				
				if(ball1 <= 9)
				{
					ball2 = GetBall(2);
				}
				else
				{
					ball2 = 0;
				}
			}
			while(ball1 + ball2 > 10);
		}		
		else 
		{
			do
			{
				ball1 = GetBall(1);
				ball2 = GetBall(2);
			}
			while((ball1 != 10) && (ball1 + ball2 > 10));
			
			if(ball1 + ball2 >= 10)
			{
				ball3 = GetBall(3);
			}
			else
			{
				ball3 = 0;
			}
		}
		
		printf("\n");
		
		ComputeScore(score, ball1fm2, ball2fm2, ball1fm1, ball2fm1, ball1, 
					 ball2, ball3, frame);
		
		PrintScore(score);
		
	}
}

/******************************************************************************
 * int GetBall(int ball)
 *
 * This function obtains the number of pins knocked down for a particular ball 
 * thrown and returns this amount of pins.
 * 
******************************************************************************/

int GetBall(int ball)
{
	int i, balln;
	char input[BUFSIZ + 1];
	int doneInput, goodInput;
	
	goodInput = FALSE;
	
	while(!(goodInput))
	{		
		printf("Enter the number of pins for ball %d: ", ball);
	
		i = 0;
		doneInput = FALSE;
		
		while(!(doneInput))
		{
			input[i] = getchar();
			
			if(input[i] == '\n')
			{
				/* pop the flag */
				doneInput = TRUE;
				
				input[i] = '\0';
			}
			
			i++;
		}
		
		if((input[0] == '0') && (input[1] == '\0'))
		{
			balln = 0;
			goodInput = TRUE;
		}
		
		else if((input[0] == '1') && (input[1] == '\0'))
		{
			balln = 1;
			goodInput = TRUE;
		}
		
		else if((input[0] == '2') && (input[1] == '\0'))
		{
			balln = 2;
			goodInput = TRUE;
		}
		
		else if((input[0] == '3') && (input[1] == '\0'))
		{
			balln = 3;
			goodInput = TRUE;
		}
		
		else if((input[0] == '4') && (input[1] == '\0'))
		{
			balln = 4;
			goodInput = TRUE;
		}
		
		else if((input[0] == '5') && (input[1] == '\0'))
		{
			balln = 5;
			goodInput = TRUE;
		}
		
		else if((input[0] == '6') && (input[1] == '\0'))
		{
			balln = 6;
			goodInput = TRUE;
		}
		
		else if((input[0] == '7') && (input[1] == '\0'))
		{
			balln = 7;
			goodInput = TRUE;
		}
		
		else if((input[0] == '8') && (input[1] == '\0'))
		{
			balln = 8;
			goodInput = TRUE;
		}
		
		else if((input[0] == '9') && (input[1] == '\0'))
		{
			balln = 9;
			goodInput = TRUE;
		}
		
		else if((input[0] == '1') && (input[1] == '0') && (input[2] == '\0'))
		{
			balln = 10;
			goodInput = TRUE;
		}
	
		else
		{
			;
		}
	}
	
	return balln;
}

/******************************************************************************
 * void ComputeScore(int *score, int ball1fm2, int ball2fm2, int ball1fm1,  
 * 					 int ball2fm1, int ball1, int ball2, int ball3, int 
 * 					 frame)
 *
 * This subroutine updates the scores vector depending on the pin count for the 
 * previous few balls.
 *
******************************************************************************/

void ComputeScore(int *score, int ball1fm2, int ball2fm2, int ball1fm1, 
				  int ball2fm1, int ball1, int ball2, int ball3, int frame)
{
	/* take care of previous frames first */
	/* strike last two frames */
	if((ball1fm2 == 10) && (ball1fm1 == 10))
	{	
		score[(frame-1) - 2] = 20 + ball1;
		/* have to handle the case of strikes on frames 8 and 9 slightly differently */
		if(frame == 10)
		{
			score[(frame-1) - 1] = 20 + ball1;
		}
	}
	/* strike last frame, not this frame */
	if((ball1fm1 == 10) && (ball1 < 10))
	{
		score[(frame-1) - 1] = 10 + ball1 + ball2;
	}
	/*spare last frame */
	else if((ball1fm1 != 10) && (ball1fm1 + ball2fm1 == 10))
	{
		score[(frame-1) - 1] = 10 + ball1;
	}

	/* take care of this frame */
	if(frame < 10) /* frames other than the (possibly) 3-pin 10th frame */
	{
		if(ball1 + ball2 < 10)
			{
				score[frame-1] = ball1 + ball2;
			}
		}
	else /* the (possibly) 3-pin 10th frame */
	{
		
		/* strike first */
		if(ball1 == 10)
		{
			score[frame-1] = ball1 + ball2 + ball3;
		}
		/* spare first */
		else if(ball1 + ball2 == 10)
		{		
			score[frame-1] = ball1 + ball2 + ball3;
		}
		/* no strike, no spare */
		else
		{		
			score[frame-1] = ball1 + ball2;
		}
	}
}

/******************************************************************************
 * void PrintScore(int *score)
 *
 * This subroutine prints the scores vector.
 *
******************************************************************************/

void PrintScore(int *score)
{
	int frame, total;

	total = 0;
	
	for(frame = 1; frame <= 10; frame++)
	{
		total += score[frame-1];
	}
	
	printf("Frame\t");		
	for(frame = 1; frame <= 10; frame++)
	{
		printf("   %d", frame);
	}
	printf("   Total");	
	printf("\n");
	
	printf("\t");
	for(frame = 1; frame <= 10; frame++)
	{
		/* change spacing depending on length of frame no */
		if(frame < 10)
		{
			/* change spacing depending on length of score elt */
			if(score[frame-1] < 10)
			{
				printf("   %d", score[frame-1]);
			}
			else if(score[frame-1] < 100)
			{
				printf("  %d", score[frame-1]);
			}
			else
			{
				printf(" %d", score[frame-1]);
			}
		}
		else
		{
			/* change spacing depending on length of score elt */
			if(score[frame-1] < 10)
			{
				printf("    %d", score[frame-1]);
			}
			else if(score[frame-1] < 100)
			{
				printf("   %d", score[frame-1]);
			}
			else
			{
				printf("  %d", score[frame-1]);
			}
		}
	}
	/* change spacing depending on length of total */
	if(total < 10)
	{
		printf("       %d", total);
	}
	else if(total < 100)
	{
		printf("      %d", total);
	}
	else
	{
		printf("     %d", total);
	}
	printf("\n");
}