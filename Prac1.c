/******************************************************************************
Examples code
*******************************************************************************/

#include <stdio.h>
#include <inttypes.h>
/*
  Ejercicios de enmascaramientos.
  Lo que se busca es que imprima el valor que esta comentado,
  alterando unicamente el valor anterior utilizando los operadores bitwise.
  Todas las conversiones deberian ser posibles con una sola operacion
*/
int main()
{
    uint16_t a = 0;
    printf("\na = %X", a);
//  Como ejemplo se da el analisis de la primera operacion

//1 B0B0
//       hex           bin
//  a = 0000 = 0000 0000 0000 0000  (valor original)
//      B0B0 = 1011 0000 1011 0000  (valor que se desea)
//  Observamos que todas las diferencias radica en que los bits tienen que estar habilitados,
//  por lo tanto usaremos el operador OR (|) para convertir esos bits en '1's

//    0000 0000 0000 0000  (valor original)
// OR 1011 0000 1011 0000  (mascara para lograrlo) = (1<<15) | (3<<12) | (1<<7) | (3<<4)
//------------------------------------------------
//    1011 0000 1011 0000  (valor que se desea)
    a |= (1<<15) | (3<<12) | (1<<7) | (3<<4);
    printf("\na = %X", a);


//2 BABA

// antes =  1011 0000 1011 0000
// BABA =   1011 1010 1011 1010

    a |= (5<<9) | (5<<1);
    printf("\na = %X", a);

//3 BEBE

// antes =  1011 1010 1011 1010
// BEBE =   1011 1110 1011 1110

  a |= (14<<8) | (14<<1);
    printf("\na = %X", a);


//4 FE00

// antes =  1011 1110 1011 1110
// FE00 =   1111 1110 0000 0000

  a ^= (1<<14) ^ (3<<4) ^ (1<<7) ^	(7<<1);
    printf("\na = %X", a);

//5 FEAA
// antes =  1111 1110 0000 0000
// FEAA =   1111 1110 1010 1010

  a |=  (5<<5) | (5<<1) ;
    printf("\na = %X", a);

//6 0155

// antes =  1111 1110 1010 1010
// 0155 =   0000 0001 0101 0101
  a ^=  (7<<13) ^ (7<<10) ^(15<<6) ^(3<<4) ^ (7<<1) ;
  a |= 1;
    printf("\na = %X", a);

//7 0001

// antes =  0000 0001 0101 0101
// 0001 =   0000 0000 0000 0001
  a &=  1 ;
    printf("\na = %X", a);

//8 0100

// antes =  0000 0000 0000 0001
// 0100 =   0000 0001 0000 0000
  a |=  (1<<8) ;
  a ^= 1;

    printf("\na = %X", a);


    return 0;
}
