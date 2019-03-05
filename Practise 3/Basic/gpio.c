#include "44b.h"
#include "gpio.h"

/* Port B interface implementation */

int portB_conf(int pin, enum port_mode mode)
{
	if (pin < 0 || pin > 10)
		return -1;

	int ret = 0;

	if (mode == SIGOUT)
		// COMPLETAR si es necesario
		// COMPLETAR: poner en rPCONB el bit indicado por pin a 1 para que por
		// dicho pin en el puerto B salga la señal correspondiente del
		// controlador de memoria
		rPCONB = rPCONB | (0x01 << pin);
	else if (mode == OUTPUT)
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPCONB el bit indicado por pin a 0 para que dicho
		// pin sea un pin de salida
		rPCONB = rPCONB & ~(0x01 << pin);
	else
		ret = -1;

	return ret;
}

int portB_write(int pin, enum digital val)
{
	if (pin < 0 || pin > 10)
		return -1;

	if (val < 0 || val > 1)
		return -1;

	if (val)
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPDATB el bit indicado por pin a 1
		rPDATB = rPDATB | (0x01 << pin);
	else
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPDATB el bit indicado por pin a 0
		rPDATB = rPDATB & ~(0x01 << pin);

	return 0;
}

/* Port G interface implementation */

int portG_conf(int pin, enum port_mode mode)
{
	if (pin < 0 || pin > 7)
		return -1;

	int pos  = pin*2;

	switch (mode) {
		case INPUT:
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPCONG 00 a partir de la posición pos para
		// configurar como pin de entrada el pin indicado por el parámetro pin
		rPCONG = rPCONG & ~(0x03 << pos);
			break;
		case OUTPUT:
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPCONG 01 a partir de la posición pos para
		// configurar como pin de salida el pin indicado por el parámetro pin
		rPCONG = rPCONG & ~(0x02 << pos);
		rPCONG = rPCONG | (0x01 << pos);
			break;
		case SIGOUT:
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPCONG 10 a partir de la posición pos para
		// que salga la señal interna correspondiente por el pin indicado
		// por el parámetro pin
		rPCONG = rPCONG |  (0x02 << pos);
		rPCONG = rPCONG & ~(0x01 << pos);
			break;
		case EINT:
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPCONG 11 a partir de la posición pos para
		// habilitar la generación de interrupciones externas por el pin
		// indicado por el parámetro pin
		rPCONG = rPCONG | (0x03 << pos);
			break;
		default:
			return -1;
	}

	return 0;
}

int portG_eint_trig(int pin, enum trigger trig)
{
	int pos = pin*4;

	if (pin < 0 || pin > 7)
		return -1;

switch (trig) {
		case LLOW:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 000, para configurar interrupciones externas por nivel bajo
			rEXTINT &= ~(0x7 << pos);
			break;
		case LHIGH:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 001, para configurar interrupciones externas por nivel alto
			rEXTINT &= ~(0x7 << pos);
			rEXTINT |=  (0x1 << pos);
			break;
		case FALLING:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 010, para configurar interrupciones externas por flanco de
			// bajada
			rEXTINT &= ~(0x7 << pos);
			rEXTINT |=  (0x2 << pos);
			break;
		case RISING:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 100, para configurar interrupciones externas por flanco de
			// subida
			rEXTINT &= ~(0x7 << pos);
			rEXTINT |=  (0x4 << pos);
			break;
		case EDGE:
			// COMPLETAR: poner en rEXTINT a partir de la posición pos tres bits
			// a 110, para configurar interrupciones externas por cualquier
			// flanco
			rEXTINT &= ~(0x7 << pos);
			rEXTINT |=  (0x6 << pos);
			break;
		default:
			return -1;
	}
	return 0;
}

int portG_write(int pin, enum digital val)
{
	int pos = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	if (val < 0 || val > 1)
		return -1;

	if ((rPCONG & (0x3 << pos)) != (0x1 << pos))
		return -1;

	if (val)
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPDATG el bit indicado por pin a 1
		rPDATG = rPDATG | (0x1 << pin);
	else
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner en rPDATG el bit indicado por pin a 0
		rPDATG = rPDATG & ~(0x1 <<pin);

	return 0;
}

int portG_read(int pin, enum digital* val)
{
	int pos = pin*2;

	if (pin < 0 || pin > 7)
		return -1;

	if (rPCONG & (0x3 << pos))
		return -1;


	if (rPDATG & (0x1 << pin))
		// COMPLETAR: tomar la implementación prácticas anteriores
		*val = HIGH;
	else
		// COMPLETAR: tomar la implementación prácticas anteriores
		*val = LOW;

	return 0;
}

int portG_conf_pup(int pin, enum enable st)
{
	if (pin < 0 || pin > 7)
		return -1;

	if (st != ENABLE && st != DISABLE)
		return -1;

	if (st == ENABLE)
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner el pin de rPUPG indicado por el parametro pin al valor adecuado,
		// para activar la resistencia de pull-up
		rPUPG = rPUPG & ~(0x1 << pin);
	else
		// COMPLETAR: tomar la implementación prácticas anteriores
		// COMPLETAR: poner el pin de rPUPG indicado por el parametro pin al valor adecuado,
		// para desactivar la resistencia de pull-up
		rPUPG = rPUPG | (0x1 << pin);

	return 0;
}

