/*
 * Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
 *
 * Double degree in Mathematics-Computer engineering
 * Complutense University, Madrid.
 *
 * Description: Introduction to integer variables representation.
 */

/*
 * This file is for visualizing how and where (considering the link file)
 * the variables are stored and how do the instructions translate from c
 * code to assembly.
 */

int x; 		// 4 bytes - Global variable 0x0C000000
short y;	// 2 bytes - Global variable 0x0C000006
char z; 	// 1 byte  - Global variable 0x0C000004

int main()
{
  unsigned short a,b; // 2 bytes - 0x0000007EE 0x000007EC

  // representacion de enteros (4,2 y 1 byte)
  // Comprobar direcciones de cada uno
  // Comprobar endiannes y tamaño
  x = 3;
  y = -1;
  z = 129;
  a = x - 7;
  b = 4;

  return 0;
}