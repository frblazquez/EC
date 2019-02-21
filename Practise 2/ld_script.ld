/*---------------------------------------------------------------------
**
**  Fichero:
**    ld_script.ld  10/6/2014
**
**    Estructura de Computadores
**    Dpto. de Arquitectura de Computadores y Automática
**    Facultad de Informática. Universidad Complutense de Madrid
**
**  Propósito:
**    Script de enlazado
**
**  Notas de diseño:
**
**-------------------------------------------------------------------*/

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
 