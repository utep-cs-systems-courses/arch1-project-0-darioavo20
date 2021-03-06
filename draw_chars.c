#include "draw.h"		/* for font */
#include "stdio.h"		/* for putchar */

void print_char_11x16(char c)
{
  c -= 0x20;
  for (char row = 0; row < 11; row++) {
    unsigned short rowBits = font_11x16[c][row];
    for (char col = 0; col < 16; col++) {
      unsigned short colMask = 1 << (15-col); /* mask to select bit associated with bit */
      putchar( (rowBits & colMask) ? '*' : ' ');
    }
    putchar('\n');
  }
}

void print_char_5x7(char c)
{
  //This first loop prints the array normally so as to show a comparison 
  c -= 0x20;
  for (char row = 0; row < 5; row++)
    {
      unsigned short rowBits = font_5x7[c][row];
      for (char col = 0;col < 7; col++)
	{
	  unsigned short colMask = 1 << (6-col);
	  putchar( (rowBits & colMask) ? '*' : ' ');
	}
      putchar('\n');
    }
  putchar('\n');
  
  //This second loop is the actual lab work, i.e. what actually changes the orientation of the char
  for (char col = 6; col > -1; col--)
    {
      unsigned short colMask = 1 << (6-col);
      for (char row = 0; row < 5; row++)
	{
	  unsigned short rowBits = font_5x7[c][row];
	  putchar( (rowBits & colMask) ? '*' : ' ');
	}
      putchar('\n');
    }
}
