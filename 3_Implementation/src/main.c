/** @brief Catch The Ball Game using C language

    Use Up, Down, Right and Left arrow keys to move your bat on screen to search the ball. Press X or any key to exit from the game.
    @author SHA160
    @date September 2021
    @file main.c
    */


#include "DisplayBorder.h"

int main() 
{ 
 int batx=25,baty=13, ballx=35, bally=7;
 int x=35, y=10, ch1, ch2, b;
  
 setxy(24,1);
 printf("...Catch The Ball...") ;
 DisplayBorder();
 
 setxy(batx, baty);
 printf("===");
 
 setxy(ballx, bally);
 printf("%c",2);
 
 ch1 = getch();     /*getch() method pauses the Output Console until a key is pressed. */
 ch2 = 0;

/*When accepting arrow key, function must be called twice; first call returns 0/0xE0; second call returns actual key code.*/
  
 if (ch1 == 0xE0) 
 {  
   while(ch2=getch())
   {
  if(ch2 == 'X') exit(0);
  if(ch2 == 75) /* Left */
  {
    if(batx>11)       /* Restrict bat on left side wall */
    {
   setxy(--batx,baty);
   printf("===");     
   setxy(batx+3,baty);        /* Space to clear bat route */
   printf(" ");
    }
  }
    if(ch2 == 77) /* Right */
    {
   if(batx<37)            /* Restrict bat on right side wall */
   {
      setxy(++batx,baty);
     printf("===");
     setxy(batx-1,baty);        /* Space to clear bat route */
     printf(" ");
   }
    }   
    if(ch2 == 72) /* Up */
    {
   if(baty>6)
   {
     setxy(batx,--baty);
     printf("===");
     setxy(batx,baty+1);
     printf("   ");
   } 
    }
    if(ch2 == 80) /* Down */
    {
   if(baty<14)
   {
     setxy(batx,++baty);
     printf("===");
     setxy(batx,baty-1);
     printf("   ");
   } 
    }
    if(batx==ballx-1 && baty==bally)
    {
   setxy(ballx-9,bally+4);
   printf("...Congratulations...");
   setxy(ballx-9,bally+5);
   printf("  ...Ball Found..");
   setxy(ballx-9,bally+6);
   printf("   ...Game Over..");
   getch();
   exit(0);
    }    
  }
 } 
 getch();
 return 0; 
}
