/*
 * Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
 *
 * Double degree in Mathematics-Computer engineering
 * Complutense University, Madrid.
 *
 * Description: Introduction to types cast. Examples.
 */

/*
 * This file is for visualizing how and where (considering the link file)
 * the variables are stored and how do the instructions translate from c
 * code to assembly. We are checking the correctness of the operations.
 */

int x;		// 4 Bytes - Global variable 0x0C000000
short y;	// 2 Bytes - Global variable 0x0C000006
char z;     // 1 Bytes - Global variable 0x0C000004
float f1;	// 4 Bytes - Global variable 0x0C000008

int main() {

  // casting
    x = 234;			//Ox000000EA - 234
    y = x;				//0x00EA	 - 234
    z = x; 				//0xEA		 - 11101010

    f1 = (float) x;		//0x436A0000 - 234
    f1 = 3.4;			//0x40599994 ~ 3.4
    x = (int) f1;		//0x00000003 - 3	Perdemos precisión

    return 0;
}


