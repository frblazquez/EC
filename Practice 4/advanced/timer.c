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
**	  Funciones para el uso de los temporizadores de la placa S3CEV40.
**
**-----------------------------------------------------------------*/

/*--- ficheros de cabecera ---*/
#include "44b.h"
#include "timer.h"

int tmr_set_prescaler(int p, int  value)
{
	int offset = p*8;
	value &= 0xFF;

	if (p < 0 || p > 3)
		return -1;

	//COMPLETAR: escribir el valor value a partir de la posición offset en el
	//registro rTCFG0, para establecer el valor de pre-escalado del módulo p
	rTCFG0 &= ~(0xFF  << offset);
	rTCFG0 |=  (value << offset);

	return 0;
}

int tmr_set_divider(int d, enum tmr_div div)
{
	int ret = 0;
	int pos = d*4;

	if ((d < 0 || d > 5) 			||
		(div == D1_32  && d > 3) 	||
		(div == EXTCLK && d != 5)	||
		(div == TCLK   && d != 4))
		return -1;

	if (div == EXTCLK || div == TCLK)
		div = 4;

	//COMPLETAR: escribir el valor div a partir de la posición pos en el
	//registro rTCFG1 para establecer el valor para el divisor d
	rTCFG1 &= ~(0xF << pos);

	if(div == D1_2)
		rTCFG1 |= (0x0 << pos); //Unnecessary
	else if(div == D1_4)
		rTCFG1 |= (0x1 << pos);
	else if(div == D1_8)
		rTCFG1 |= (0x2 << pos);
	else if(div == D1_16)
		rTCFG1 |= (0x3 << pos);
	else if(div == D1_32)
		rTCFG1 |= (0x4 << pos);
	else
		return -1;

	return 0;
}

int tmr_set_count(enum tmr_timer t, int count, int cmp)
{
	int err = 0;

	switch (t) {
		case TIMER0:
			//COMPLETAR: establecer el valor de cuenta count y el valor de
			//comparación cmp en los registros de buffer del timer0 (rTCNTB0 y
			//rTCMPB0)
			rTCNTB0 = count;
			rTCMPB0 = cmp;
			break;
		case TIMER1:
			//COMPLETAR: establecer el valor de cuenta count y el valor de
			//comparación cmp en los registros de buffer del timer1 (rTCNTB1 y
			//rTCMPB1)
			rTCNTB1 = count;
			rTCMPB1 = cmp;
			break;
		case TIMER2:
			//COMPLETAR: establecer el valor de cuenta count y el valor de
			//comparación cmp en los registros de buffer del timer2 (rTCNTB2 y
			//rTCMPB2)
			rTCNTB2 = count;
			rTCMPB2 = cmp;
			break;
		case TIMER3:
			//COMPLETAR: establecer el valor de cuenta count y el valor de
			//comparación cmp en los registros de buffer del timer3 (rTCNTB3 y
			//rTCMPB3)
			rTCNTB3 = count;
			rTCMPB3 = cmp;
			break;
		case TIMER4:
			//COMPLETAR: establecer el valor de cuenta count y el valor de
			//comparación cmp en los registros de buffer del timer4 (rTCNTB4 y
			//rTCMPB4)
			rTCNTB4 = count;
			rTCMPB4 = cmp;
			break;
		case TIMER5:
			//COMPLETAR: establecer el valor de cuenta count en el registro de 
			//buffer del timer5 (rTCNTB5)
			rTCNTB5 = count;
			break;
		default:
			err = -1;
	}

	return err;
}

int tmr_update(enum tmr_timer t)
{
	if (t < 0 || t > 5)
		return -1;

	int pos;

	if(t == 0) 		pos = 1;
	else 			pos = t*4 + 5;

	//COMPLETAR: poner a 1 en el registro rTCON el bit indicado por pos 
	// y justo después ponerlo a 0 (deben ser stores distintos, lo hacemos con
	// sentencias C distintas)

	rTCON |=  (0x1 << pos);
	rTCON &= ~(0x1 << pos);

	return 0;
}

int tmr_set_mode(enum tmr_timer t, enum tmr_mode mode)
{
	if (t < 0 || t > 5)
		return -1;

	int err = 0;
	int pos;

	if(t == 0) 	pos = 3;
	else  		pos = t*4 + 7;

	if (mode == ONE_SHOT)
		//COMPLETAR: poner a 0 el bit autoreload a partir de la posición pos (es
		//el cuarto bit a partir de esa posición)
		rTCON &= ~(0x1 << pos);
	else if (mode == RELOAD)
		//COMPLETAR: poner a 1 el bit autoreload a partir de la posición pos (es
		//el cuarto bit a partir de esa posición)
		rTCON |=  (0x1 << pos);
	else
		err = -1;

	return err;
}

int tmr_start(enum tmr_timer t)
{
	if (t < 0 || t > 5)
		return -1;

	int pos = t*4;
	if(t > 0)
		pos += 4;

	//COMPLETAR: poner a 1 el bit de start a partir de la posición pos en el
	//registro rTCON (es el primer bit del grupo
	rTCON |= (0x1 << pos);

	return 0;
}

int tmr_stop(enum tmr_timer t)
{
	if (t < 0 || t > 5)
		return -1;

	int pos = t*4;
	if (t > 0)
		pos += 4;

	//COMPLETAR: poner a 0 el bit de start a partir de la posición pos en el
	//registro rTCON (es el primer bit del grupo
	rTCON &= ~(0x1 << pos);


	return 0;
}

int tmr_isrunning(enum tmr_timer t)
{
	int ret = 0;
	int pos = t*4;
	if (t > 0)
		pos += 4;

	if ((t >= 0) && (t <= 5) 
			&& (rTCON & (0x1 << pos)))
		ret = 1;

	return ret;
}

