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

#ifndef BUTTON_H_
#define BUTTON_H_

#define BUT1 0x1
#define BUT2 0x2

unsigned int read_button(void);

#endif /* BUTTON_H_ */
