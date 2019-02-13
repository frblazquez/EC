/*
 * Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
 *
 * Double degree in Mathematics-Computer engineering
 * Complutense University, Madrid.
 *
 * Description: Introduction to char variables representation.
 */

/*
 * This file is for visualizing how and where (considering the link file)
 * the variables are stored and how do the instructions translate from c
 * code to assembly.
 */

char x;		// 1 Byte - Global variable 0x0C000000
char y;		// 1 Byte - Global variable 0x0C000001

int main()
{
  char a;   // 1 Byte - Local variable 0x0c7FEFF

 // Comprobar lo que se almacena en cada caso
 // y lo que se representaría por pantalla
 // si se imprimiesen como caracteres

  x = 'a';		// x ~ 'a'
  y = x + 3;	// y ~ 'd'
  a = x - 32;	// a ~ 'A'

  return 0;
}
