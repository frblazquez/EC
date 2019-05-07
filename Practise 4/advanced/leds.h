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

#ifndef _LEDS_H_
#define _LEDS_H_

void leds_init( void );
void led1_on( void );
void led1_off( void );
void led2_on( void );
void led2_off( void );
void led1_switch( void );
void led2_switch( void );
void leds_switch( void );
void leds_display( unsigned int leds_status );

#endif
