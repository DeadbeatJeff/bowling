/******************************************************************************
 * main.c
 *
 * This program calculates bowling scores for 1 player.
 *
 * Author:        Jeffrey Rolland
 * Creation Date: 11/06/2004
 * Modifications: None
 *         ******************************************************************************/

/******************************************************************************
 * 
 * header inclusions
 * 
******************************************************************************/

#include "MyInfo.h"
#include "Bowling.h"

/******************************************************************************
 * int main(void)
 *
 * This is the main function. It calls a function to display information, then 
 * begins the main program.
 * 
******************************************************************************/
 
int main(void)
{
	MyInfo("5+i", __DATE__, __TIME__);
	Bowling();

	return 0;
}