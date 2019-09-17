/*-------------------------------------------------------------------
**
**	  Francisco Javier Bl�zquez Mart�nez  ~  frblazqu@ucm.es 
**      
**	  Doble grado en Ingenier�a inform�tica - Matem�ticas
**	  Universidad Complutense de Madrid. Curso 2018/19
**
**    Estructura de Computadores. Facultad de Inform�tica.
**
**    Descripci�n: 
**	  Funciones para el uso del display 7 segmentos de la placa S3CEV40.
**
**-----------------------------------------------------------------*/

#ifndef D8LED_H_
#define D8LED_H_

void D8Led_init(void);
void D8Led_segment(int value); 
void D8Led_digit(int value); 

#endif

