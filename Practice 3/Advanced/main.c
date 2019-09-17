#include <stdio.h>
#include "44b.h"
#include "button.h"
#include "leds.h"
#include "utils.h"
#include "D8Led.h"
#include "intcontroller.h"
#include "timer.h"
#include "gpio.h"
#include "keyboard.h"

struct RLstat {
	int moving;
	int speed;
	int direction;
	int position;
};

static struct RLstat RL = {
	.moving = 1,
	.speed = 5,
	.direction = 1,
	.position = 0,
};

static int pulsaciones = 0;
static int timer0_ptr = 0;
static int timer1_ptr = 3;
static int stopped = 0;

void timer0_ISR(void) 	__attribute__ ((interrupt ("IRQ")));
void timer1_ISR(void) 	__attribute__ ((interrupt ("IRQ")));
void timer2_ISR(void) 	__attribute__ ((interrupt ("IRQ")));
void timer3_ISR(void) 	__attribute__ ((interrupt ("IRQ")));
void button_ISR(void) 	__attribute__ ((interrupt ("IRQ")));
void keyboard_ISR(void) __attribute__ ((interrupt ("IRQ")));

void timer0_ISR(void)
{
	//COMPLETAR: tomar el código de avance de posición del led rotante de la práctica anterior

		// COMPLETAR: debemos hacer avanzar el led rotante una posición en
		// la dirección indicada por el campo direction de la variable RL.
		// La posición actual está representada en el campo position.
		// Recordar que queremos un movimiento circular, representado por
		// las 6 primeras posiciones en el array Segmentes del display de 8
		// segmentos, por lo que position debe estar siempre entre 0 y 5.

	if(timer0_ptr == 5)	timer0_ptr = 0;
	else				timer0_ptr++;

	D8Led_two_segments(timer0_ptr, timer1_ptr);

	ic_cleanflag(INT_TIMER0);
}

void timer1_ISR(void)
{
	//COMPLETAR: tomar el código de avance de posición del led rotante de la práctica anterior

		// COMPLETAR: debemos hacer avanzar el led rotante una posición en
		// la dirección indicada por el campo direction de la variable RL.
		// La posición actual está representada en el campo position.
		// Recordar que queremos un movimiento circular, representado por
		// las 6 primeras posiciones en el array Segmentes del display de 8
		// segmentos, por lo que position debe estar siempre entre 0 y 5.

	if(timer1_ptr == 5)	timer1_ptr = 0;
	else				timer1_ptr++;

	D8Led_two_segments(timer0_ptr, timer1_ptr);

	ic_cleanflag(INT_TIMER1);
}

void timer2_ISR(void)
{
	//COMPLETAR: tomar el código de avance de posición del led rotante de la práctica anterior

		// COMPLETAR: debemos hacer avanzar el led rotante una posición en
		// la dirección indicada por el campo direction de la variable RL.
		// La posición actual está representada en el campo position.
		// Recordar que queremos un movimiento circular, representado por
		// las 6 primeras posiciones en el array Segmentes del display de 8
		// segmentos, por lo que position debe estar siempre entre 0 y 5.

	led1_on();
	led2_on();

	tmr_stop(TIMER0);
	tmr_stop(TIMER1);
	tmr_stop(TIMER3);

	ic_cleanflag(INT_TIMER2);
}

void timer3_ISR(void)
{
	//COMPLETAR: tomar el código de avance de posición del led rotante de la práctica anterior

		// COMPLETAR: debemos hacer avanzar el led rotante una posición en
		// la dirección indicada por el campo direction de la variable RL.
		// La posición actual está representada en el campo position.
		// Recordar que queremos un movimiento circular, representado por
		// las 6 primeras posiciones en el array Segmentes del display de 8
		// segmentos, por lo que position debe estar siempre entre 0 y 5.
	leds_switch();

	ic_cleanflag(INT_TIMER3);
}

void button_ISR(void)
{
	unsigned int whicheint = rEXTINTPND;
	unsigned int buttons = (whicheint >> 2) & 0x3;

	//COMPLETAR: usar el código de la primera parte parte de atención a los
	//pulsadores

		if (~buttons & BUT1) {
			// COMPLETAR: utilizando la interfaz para los leds definida en leds.h
			// hay que apagar ambos leds
			// También hay que comutar la dirección del movimiento del led rotante
			// representado por el campo direction de la variable RL
			if(tmr_isrunning(TIMER0))
			{
				tmr_stop(TIMER2);
				tmr_stop(TIMER0);
				tmr_stop(TIMER1);
				tmr_stop(TIMER3);

				stopped = 1;
			}
			else
			{
				if(!stopped)
				{
				led1_on();
				led2_off();

				tmr_stop(TIMER2);

				tmr_start(TIMER0);
				tmr_start(TIMER1);
				tmr_start(TIMER2);
				tmr_start(TIMER3);
				}

				else
				{
					tmr_start(TIMER0);
					tmr_start(TIMER1);
					tmr_start(TIMER2);
					tmr_start(TIMER3);

					stopped = 0;
				}
			}

		}
		if (~buttons & BUT2) {
			// COMPLETAR: utilizando la interfaz para los leds definida en leds.h
			// Incrementar contador de pulsaciones. Si es par, conumtar led1. Si es impar, conmutar el led2.
			// También hay que comutar el estado de movimiento del led rotante
			// representado por el campo moving de la variable RL, y en caso de
			// ponerlo en marcha debemos reiniciar el campo iter al valor del campo
			// speed.
			pulsaciones++;

			if((pulsaciones%2)==0)
				led1_switch();
			else
				led2_switch();

			if(RL.moving)
				RL.moving = 0;
			else
				RL.moving = 1;
		}

	// eliminamos rebotes
	Delay(2000);

	// borramos el flag en extintpnd
	// Va a borrar tanto la primera petición como la segunda!

	//COMPLETAR: debemos borrar las peticiones de interrupción en
	//EXTINTPND escribiendo un 1 en los flags que queremos borrar (los
	//correspondientes a los pulsadores pulsados)
	rEXTINTPND |= (0x3 << 2);
	ic_cleanflag(INT_EINT4567);
}

void keyboard_ISR(void)
{
	int key;

	/* Eliminar rebotes de presión */
	Delay(200);
	
	/* Escaneo de tecla */
	key = kb_scan();

	if (key != -1) {
		/* Visualizacion en el display */
		//COMPLETAR: mostrar la tecla en el display utilizando el interfaz
		//definido en D8Led.h
		//D8Led_digit(key);

		switch (key) {

//		SIMPLEMENTE CÓDIGO DE REFENECIA PARA MÁS ABAJO
//
//		tmr_set_prescaler(0, 255);		// Preescalado = 255
//		tmr_set_divider(0, D1_8);		// Factor de división = 1/8
//		tmr_set_count(TIMER0, 62500, 1);// Valor de cuenta = 62500
//		tmr_set_mode(TIMER0, RELOAD);	// Modo de funcionamiento auto-reload
//		tmr_update(TIMER0);				// Actualizamos el contador

			case 0:
				//COMPLETAR: poner en timer0 divisor 1/8 y contador 62500
				tmr_set_divider(0,D1_8);
				tmr_set_count(TIMER0,62500,1);
				tmr_update(TIMER0);
				break;
			case 1:
				//COMPLETAR: poner en timer0 timer divisor 1/8 y contador 31250
				tmr_set_divider(0,D1_8);
				tmr_set_count(TIMER0,31250,1);
				tmr_update(TIMER0);
				break;
			case 2:
				//COMPLETAR: poner en timer0 timer divisor 1/8 y contador 15625
				tmr_set_divider(0,D1_8);
				tmr_set_count(TIMER0,15625,1);
				tmr_update(TIMER0);
				break;
			case 3:
				//COMPLETAR: poner en timer0 timer divisor 1/4 y contador 15625
				tmr_set_divider(0,D1_4);
				tmr_set_count(TIMER0,15625,1);
				tmr_update(TIMER0);
				break;
			case 4:
							//COMPLETAR: poner en timer0 divisor 1/8 y contador 62500
							tmr_set_divider(1,D1_8);
							tmr_set_count(TIMER1,62500,1);
							tmr_update(TIMER1);
							break;
						case 5:
							//COMPLETAR: poner en timer0 timer divisor 1/8 y contador 31250
							tmr_set_divider(1,D1_8);
							tmr_set_count(TIMER1,31250,1);
							tmr_update(TIMER1);
							break;
						case 6:
							//COMPLETAR: poner en timer0 timer divisor 1/8 y contador 15625
							tmr_set_divider(1,D1_8);
							tmr_set_count(TIMER1,15625,1);
							tmr_update(TIMER1);
							break;
						case 7:
							//COMPLETAR: poner en timer0 timer divisor 1/4 y contador 15625
							tmr_set_divider(1,D1_4);
							tmr_set_count(TIMER1,15625,1);
							tmr_update(TIMER1);
							break;
			default:
				break;
		}
		
		//tmr_update(TIMER0);
		/* Esperar a que la tecla se suelte, consultando el registro de datos */		
		while (!(rPDATG & 0x2))/*COMPLETAR: true si está pulsada la tecla (leer del registro rPDATG)*/;
	}

    /* Eliminar rebotes de depresión */
    Delay(200);
     
    /* Borrar interrupciones pendientes */
	//COMPLETAR
	//borrar la interrupción por la línea EINT1 en el registro rI_ISPC
    ic_cleanflag(INT_EINT1);
}

int setup(void)
{
	leds_init(); led1_on();
	D8Led_init();
	D8Led_two_segments(timer0_ptr, timer1_ptr);

	//D8Led_segment(RL.position);

	/********************************************************************************/
	// Port G: configuración para generación de interrupciones externas,
	//         botones y teclado

	//COMPLETAR: utilizando el interfaz para el puerto G definido en gpio.h
	//configurar los pines 1, 6 y 7 del puerto G para poder generar interrupciones
	//externas por flanco de bajada por ellos y activar las correspondientes
	//resistencias de pull-up.
	portG_conf(1, EINT);
	portG_conf(6, EINT);
	portG_conf(7, EINT);

	portG_conf_pup(1, ENABLE);	// Desactivamos la resitencia de pull-up del puerto 1
	portG_conf_pup(6, ENABLE);  // Desactivamos la resitencia de pull-up del puerto 6
	portG_conf_pup(7, ENABLE);  // Desactivamos la resitencia de pull-up del puerto 7

	portG_eint_trig(1,FALLING);	// Interrupciones en el puerto 1 por flanco de bajada
	portG_eint_trig(6,FALLING); // Interrupciones en el puerto 6 por flanco de bajada
	portG_eint_trig(7,FALLING); // Interrupciones en el puerto 7 por flanco de bajada

	/********************************************************************************/
	/* Configuración del timer */

	//COMPLETAR: tomar el código de la segunda parte
	tmr_set_prescaler(0, 255);		// Preescalado = 255
	tmr_set_divider(0, D1_8);		// Factor de división = 1/8
	tmr_set_count(TIMER0, 31250, 1);// Valor de cuenta = 62500
	tmr_set_mode(TIMER0, RELOAD);	// Modo de funcionamiento auto-reload
	tmr_update(TIMER0);				// Actualizamos el contador
	tmr_stop(TIMER0);

	//tmr_set_prescaler(0, 255);	// Preescalado = 255
	tmr_set_divider(1, D1_8);		// Factor de división = 1/8
	tmr_set_count(TIMER1, 31250, 1);// Valor de cuenta = 62500
	tmr_set_mode(TIMER1, RELOAD);	// Modo de funcionamiento auto-reload
	tmr_update(TIMER1);				// Actualizamos el contador
	tmr_stop(TIMER1);

	/**********************************************************************************/
	tmr_set_prescaler(1, 255);		// Preescalado = 255
	tmr_set_divider(2, D1_32);		// Factor de división = 1/8
	tmr_set_count(TIMER2, 62500, 1);// Valor de cuenta = 62500
	tmr_set_mode(TIMER2, ONE_SHOT);	// Modo de funcionamiento auto-reload
	tmr_update(TIMER2);				// Actualizamos el contador
	tmr_stop(TIMER2);

	//tmr_set_prescaler(1, 255);	// Preescalado = 255
	tmr_set_divider(3, D1_4);		// Factor de división = 1/8
	tmr_set_count(TIMER3, 31250, 1);// Valor de cuenta = 62500
	tmr_set_mode(TIMER3, RELOAD);	// Modo de funcionamiento auto-reload
	tmr_update(TIMER3);				// Actualizamos el contador
	tmr_stop(TIMER3);

	//tmr_start(TIMER0);
	//tmr_start(TIMER1);
	/********************************************************************************/
	// Registramos las ISRs
	pISR_TIMER0   =  timer0_ISR;		//COMPLETAR: registrar la RTI del timer
	pISR_TIMER1   =  timer1_ISR;
	pISR_TIMER2   =  timer2_ISR;
	pISR_TIMER3   =  timer3_ISR;
	pISR_EINT4567 =	 button_ISR;	//COMPLETAR: registrar la RTI de los botones
	pISR_EINT1    =  keyboard_ISR;	//COMPLETAR: registrar la RTI del teclado

	/* Configuración del controlador de interrupciones
	 * Habilitamos la línea IRQ, en modo vectorizado
	 * Configuramos el timer 0 en modo IRQ y habilitamos esta línea
	 * Configuramos la línea EINT4567 en modo IRQ y la habilitamos
	 * Configuramos la línea EINT1 en modo IRQ y la habilitamos
	 */

	/********************************************************************************/
	//COMPLETAR: utilizando el interfaz definido en intcontroller.h
	//		habilitar la línea IRQ en modo vectorizado
	//		deshabilitar la línea FIQ
	//		configurar la línea INT_TIMER0   en modo IRQ
	//		configurar la línea INT_EINT4567 en modo IRQ
	//		configurar la línea INT_EINT1    en modo IRQ
	//		habilitar la línea INT_TIMER0
	//		habilitar la línea INT_EINT4567
	//		habilitar la línea INT_EINT1

	ic_init();					// Inicialización de interrupciones (todas enmascaradas)
	ic_conf_irq(ENABLE, VEC);	// Habilitamos las IRQ vectorizadas
	ic_conf_fiq(DISABLE);		// Deshabilitamos las FIQ

	ic_conf_line(INT_TIMER0  ,IRQ);	// Configuramos el timer0 para interrupciones IRQ
	ic_conf_line(INT_TIMER1,  IRQ);
	ic_conf_line(INT_TIMER2,  IRQ);
	ic_conf_line(INT_TIMER3,  IRQ);

	ic_conf_line(INT_EINT4567,IRQ);	// Configuramos EINT4567  para interrupciones IRQ
	ic_conf_line(INT_EINT1   ,IRQ);	// Configuramos EINT1     para interrupciones IRQ

	ic_enable(INT_GLOBAL);			// Permitimos que se habiliten interrupciones
	ic_enable(INT_TIMER0);			// Habilitamos la línea de interrupción del timer 0
	ic_enable(INT_TIMER1);
	ic_enable(INT_TIMER2);
	ic_enable(INT_TIMER3);

	ic_enable(INT_EINT4567);		// Habilitamos la línea de interrupción del eint4567
	ic_enable(INT_EINT1);			// Habilitamos la línea de interrupción del eint1
	/********************************************************************************/

	Delay(0);
	return 0;
}

int loop(void)
{
	return 0;
}


int main(void)
{
	setup();

	while (1) {
		loop();
	}
}