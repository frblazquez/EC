/*-------------------------------------------------------------------
**
**    Francisco Javier Bl�zquez Mart�nez  ~  frblazqu@ucm.es 
**      
**    Doble grado en Ingenier�a inform�tica - Matem�ticas
**    Universidad Complutense de Madrid. Curso 2018/19
**
**    Estructura de Computadores. Facultad de Inform�tica.
**
**    Descripci�n: 
**    Script de enlazado gen�rico para la simulaci�n en EclipseARM y ejecuci�n
**    en la placa S3CEV40.
**
**-----------------------------------------------------------------*/

SECTIONS
{
    . = 0x0C100000;
    .data : {
      *(.data*)
      *(.rodata*) 
    }
	Image_ZI_Base = .;
    .bss : { 
      *(.bss*)
      *(COMMON)
    }
	Image_ZI_Limit = .;
    .text : { 
      *(.text*)
    }
    PROVIDE( end = . );
}
GROUP(
   libgcc.a
   libg.a
   libc.a
   libm.a
   libnosys.a
 )
 
