/** @brief Catch The Ball Game using C language
    Use Up, Down, Right and Left arrow keys to move your bat on screen to search the ball. Press X or any key to exit from the game.
    @author SHA160
    @date September 2021
    @file DisplayBorder.c
    */

#include "DisplayBorder.h"

void DisplayBorder();

COORD c = {0, 0};
/*
COORD defines the coordinates of a character cell in a console screen buffer.
The origin of the coordinate system (0,0) is at the top, left cell of the buffer.
*/
void setxy (int x, int y)
{
/* Set X and Y coordinates */
 c.X = x;
 c.Y = y;
 SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void DisplayBorder()
{
 int i, j;
 
 //Top border line...
 setxy(20,5); 
 for(j=0; j<30; j++)
  printf("%c", 223);
 
 //Bottom border line... 
 setxy(20,15);
 for(j=0; j<=30; j++)
  printf("%c", 223);
 
 //Left and Right border line...
 for(j=0; j<10; j++)
 {
  setxy(20,5+j);
  printf("%c",219);
  
  setxy(50,5+j);
  printf("%c",219);
 }
 printf("\n");
}
