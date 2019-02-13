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
 * code to assembly. We are checking the correctness of the operations.
 */

float f1; // 4 Bytes - Global variable 0x0C000008
float f2; // 4 Bytes - Global variable 0x0C000004
float f3; // 4 Bytes - Global variable 0x0C000000

int main() {

  f1 = 1.2;   // 0x3F99999A - 00111111 10011001 10011001 10011010
  f2 = 1.1;   // 0x3F8CCCCD - 00111111 10001100 11001100 11001101
  f3 = f1- f2;  // 0x3DCCCCD0 - 00111101 11001100 11001100 11010000

  // Comprobar su representacion en memoria y pasadlo de nuevo a base 10

  f1 = 1300235677; // 0x4E9B000B - 01001110100110110000000000001011
                   // 1300235648 - Hay una pérdida de precisión
  f2 = 0.03;     // 0x3CF5C28F - 00111100 11110101 11000010 10001111
           // 0.02999999932944774627685546875

  //  comprobad el resultado

  f3 = f1 + f2;    // 0x4E9B000B - 01001110 10011011 00000000 00001011
                   // 1300235648 - Se queda exactamente igual


  f1 = 1300235677;        // 0x4E9B000B  - 1300235648
  f2 = f1 / 123.8;        // 0x4B204237  - 10502711
  f3 = f1 - (f2*123 + f2*0.8);  // 0x40E66666 ~= 7.2 ¡Debería ser 0!

  if (f3 == 0.0)
    f3 = 1.0;
  else
    f3 = 2.0;

  return 0;

}
