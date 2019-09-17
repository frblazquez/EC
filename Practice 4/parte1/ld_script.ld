/*-------------------------------------------------------------------
**
**    Francisco Javier Blázquez Martínez  ~  frblazqu@ucm.es 
**      
**    Doble grado en Ingeniería informática - Matemáticas
**    Universidad Complutense de Madrid. Curso 2018/19
**
**    Estructura de Computadores. Facultad de Informática.
**
**    Descripción: 
**    Script de enlazado genérico para la simulación en EclipseARM y ejecución
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
 
