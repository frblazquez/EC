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

int x;              // 4 Bytes - Global variable 0x0C000000
short y1;           // 2 Bytes - Global variable 0x0C000008
unsigned short y2;  // 2 Bytes - Global variable 0x0C000004
char z;             // 1 Byte  - Global variable 0x0C000006

int main() {
  unsigned short a,b; // 2x2 Bytes - 0x0C7FEFEE 0x0C7FEFEC

  x=9;            // 0x00000009
  z = x + 126;    // 0x87     - (¡podemos haber cambiado el signo!)
  a = 4;          // 0x0004
  b = a - 7;      // 0xFFFD   - (¡pero no lo interpreta como negativo!)

  z = 9 /2;       // 0x04 - Redondea al 4

  // y1 es signed short
  y1 = 128*128 + (128*128-1); // (2^7*2^7) + (2^14-1)
  y1 = y1 + 1;                // Comprobar resultado

  // y1     = 0111111111111111  máximo positivo
  // y1 + 1 = 1000000000000000  mínimo negativo (ha desbordado)

  // y2 es unsigned short
  y2 = 128*128 + (128*128-1); // (2^7*2^7) + (2^14-1)
  y2 = y2 + 1;                // Comprobar resultado

  // y2     = 0111111111111111
  // y2 + 1 = 1000000000000000  no desborda por usar unsigned

  y2 = 256*128 + (256*128-1); // (2^8*2^7) + (2^15-1)
  y2 = y2 + 1;                // Comprobar resultado

  // y2     = 1111111111111111
  // y2 + 1 = 0000000000000000  ahora sí que desborda

  return 0;
}
