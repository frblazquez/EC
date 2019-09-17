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
**	  Funciones para el uso de los leds de la placa S3CEV40.
**
**-----------------------------------------------------------------*/

#include "44b.h"
#include "leds.h"
#include "gpio.h"

// Mascaras de bits
#define LED1 0x01
#define LED2 0x02
#define BIT_LED1 9
#define BIT_LED2 10

// status representa el estado de los leds
// sólo tienen sentido los dos bites menos
// significativos, cada uno para un led
// 1 encendido y 0 apagado
static unsigned int status = 0;

void leds_init( void )
{
	//COMPLETAR: tomar la implementación de la primera parte
	//COMPLETAR usando el interfaz del puerto B definido en gpio.h
	// hay que configurar los pines 9 y 10 como pines de salida

	portB_conf(9,  OUTPUT);
	portB_conf(10, OUTPUT);

	leds_display( status );
}

void led1_on( void )
{
	status |=  LED1;
	leds_display( status );
}

void led1_off( void )
{
	status &=  ~LED1;
	leds_display( status );
}

void led2_on( void )
{
	status |=  LED2;
	leds_display( status );
}

void led2_off( void )
{
	status &=  ~LED2;
	leds_display( status );
}

void led1_switch( void )
{
	status ^= LED1;
	leds_display( status );
}

void led2_switch( void )
{
	status ^= LED2;
	leds_display( status );
}

void leds_switch( void ){
	status ^= (LED1 | LED2);
	leds_display( status );
}

void leds_display( unsigned int leds_status )
{
	status = leds_status;
	
	// Recordamos que ambos leds funcionan con lógica negada. (Ver manual)
	if( status & LED1 )
		//COMPLETAR usando el interfaz del puerto B definido en gpio.h
		//hay que poner a nivel bajo el bit correspondiente al led 1
		portB_write(9, LOW);
	else
		//COMPLETAR usando el interfaz del puerto B definido en gpio.h
		//hay que poner a nivel alto el bit correspondiente al led 1
		portB_write(9, HIGH);

	if( status & LED2 )
		//COMPLETAR usando el interfaz del puerto B definido en gpio.h
		//hay que poner a nivel bajo el bit correspondiente al led 2
		portB_write(10, LOW);
	else
		//COMPLETAR usando el interfaz del puerto B definido en gpio.h
		//hay que poner a nivel alto el bit correspondiente al led 2
		portB_write(10, HIGH);
}
