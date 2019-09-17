/*-------------------------------------------------------------------
**
**	  Francisco Javier Blázquez Martínez  ~  frblazqu@ucm.es 
**      
**	  Doble grado en Ingeniería informática - Matemáticas
**	  Universidad Complutense de Madrid. Curso 2018/19
**
**    Estructura de Computadores. Facultad de Informática.
**
**    Descripción: 
**	  Funciones para el control de los pulsadores de la placa S3CEV40.
**
**-----------------------------------------------------------------*/

#include "44b.h"
#include "utils.h"
#include "button.h"
#include "leds.h"
#include "gpio.h"

unsigned int read_button(void)
{
	unsigned int buttons = 0;
	enum digital valButton1, valButton2;

	//COMPLETAR utilizando el interfaz del puerto G de gpio.h debemos leer los
	//pines 6 y 7 del puerto G (portG_read) debemos devolver un valor (buttons)
	//en el que el bit 0 (el menos significativo) representa el estado del botón
	//del pin 6 y el bit 1 representa el estado del botón del pin 7 (a 1 si
	//están pulsados a 0 si no lo están).

	portG_read(6, &valButton1);	// Leemos el pin 6 del puerto G
	portG_read(7, &valButton2);	// Leemos le pin 7 del puerto G

	// Recordamos que el boton está pulsado si lo que leemos del puerto G es 0 (Lógica negada)
	if(valButton1 == LOW) 	buttons = buttons | BUT1;	// Pin 6 a cero => pulsador 1 pulsado
	if(valButton2 == LOW)	buttons = buttons | BUT2;	// Pin 7 a cero => pulsador 2 pulsado

	return buttons;
}


