/*
 * Francisco Javier Blázquez Martínez ~ frblazqu@ucm.es
 *
 * Double degree in Mathematics-Computer engineering
 * Complutense University, Madrid.
 *
 * Description: Introduction to memory location of complex types.
 */

/*
 * This file is for visualizing how and where (considering the link file)
 * the variables are stored and how do the instructions translate from c
 * code to assembly. We are checking the correctness of the operations.
 */
struct t_dummy {
	char cx;
	char cy;
	int lat;
	int longitud;
};

struct t_dummy st;

unsigned int tabla[8]= { 0x1, 0x3, 0x5, 0x7, 0x9, 0xB, 0xD, 0xF };

// Operaciones sobre bits
#define LED1 0x01
#define LED2 0x02
static unsigned int status = 0;
// Punteros
unsigned int * puntero;
char str_tecla[27] = "\nTecla pulsada\0";	// 0x0c000020 - 28 Bytes
char * puntero2;

/*
 * tabla      ~ 0x0C000000 ~ 8x4 Bytes
 * std_tecla  ~ 0x0C000020 ~ 28  Bytes
 * puntero2   ~ 0x0C000040 ~ 1   Byte
 * puntero    ~ 0x0C000044 ~ 1   Byte
 * st		  ~ 0x0C000048 ~ 12  Bytes
 * status     ~ 0x0C00003C ~ 1   Byte
 */

int main() {

	st.cx = 1;			// Ver 0x0C000048
	st.cy = 2;			// Ver 0x0C000049
	st.lat = 3;			// Ver 0x0C00004C
	st.longitud = 4;	// Ver 0x0C000050

	status |=  LED1;			// status = status 0R  LED1
	status &=  ~LED1;			// status = status AND NOT(LED1)
	status ^= (LED1 | LED2);	// status = status XOR (LED1 0R LED2)
	status = (tabla[7]<< 4 ) | tabla [2] | (tabla[4]<<8);
	status  = (status & ~(0xf << 12)) | (0x7 << 12);
// punteros y cadenas de caracteres
	puntero = tabla;
	puntero++;

	puntero2 = str_tecla;
	return 0;
}
