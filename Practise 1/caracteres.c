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

char x;
char y;

int main() 
{
  char a;
   
 // Comprobar lo que se almacena en cada caso
 // y lo que se representaría por pantalla
 // si se imprimiesen como caracteres
  x = 'a'; 
  y = x + 3; 
  a = x - 32; 

  return 0; 
}
