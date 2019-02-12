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

float f1;	// 4 bytes - 
float f2; 	// 4 bytes - 
double d1;	// 8 bytes - 

int main() 
{
  // Representacion de reales en punto flotante
  // Comprobar la ubicacion de cada variable
  // Determinar mantisa y exponente de cada uno
  
  f1 =  1.2;  
  f2 = -1.1;  
  d1 =  1.2;

  return 0;
}
