/*
 * Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
 *
 * Double degree in Mathematics-Computer engineering
 * Complutense University, Madrid.
 *
 * Description: Introduction to float and double variables.
 */

/*
 * This file is for visualizing how and where (considering the link file)
 * the variables are stored and how do the instructions translate from c
 * code to assembly.
 */

float f1;	// 4 bytes - Global variable 0x0C00000C
float f2; 	// 4 bytes - Global variable 0x0C000008
double d1;	// 8 bytes - Global variable 0x0c000000

int main()
{
  // Representacion de reales en punto flotante
  // Comprobar la ubicacion de cada variable
  // Determinar mantisa y exponente de cada uno

  f1 =  1.2;  // f1 ~ 0x3F99999A
  	  	  	  // f1 ~ 0  01111111  00110011001100110011010
  f2 = -1.1;  // f2 ~ 0xBF8CCCCD
  	  	  	  // f2 ~ 1  01111111  00011001100110011001101
  d1 =  1.2;  // f3 ~ 0x3FF3333333333333
  	  	  	  // f3 ~ 00111111 11110011 00110011 00110011
  	  	  	  //  	  00110011 00110011 00110011 00110011
  return 0;
}
