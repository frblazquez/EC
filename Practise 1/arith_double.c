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

double f1; 	// 8 Bytes - Global variable 0x0C000010
double f2;	// 8 Bytes - Global variable 0x0C000008
double f3;	// 8 Bytes - Global variable 0x0C000000

int main() {

  f1 = 1.2;		// 0x3FF3333333333333
  f2 = 1.1;		// 0x3FF199999999999A
  f3 = f1- f2;  // 0x3FB9999999999990  - 0.099999999999999   (Muy exacto)

  // Comprobar su representacion en memoria y pasadlo de nuevo a base 10
  f1 = 1300235677;	// 0x41D3600167400000
  f2 = 0.03;		// 0x3F9EB851EB851EB8
  f3 = f1 + f2; 	// 0x41D360016741EB85	- 1300235677.0299(Muy exacto)


  f1 = 1300235677;	// 0x41D3600167400000
  f2 = f1 / 123.8;	// 0x41640846EE44A715
  f3 = f1 - (f2*123 + f2*0.8); // 0x0000000000000000 (Exacto)

  if (f3 == 0.0)
    f3 = 1.0;
  else
    f3 = 2.0;

  return 0;

}
