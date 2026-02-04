#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern void *Y;
extern  int incY;
extern int i;
extern int lenY;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i_inner;
for (i = 0; i < lenY; i++) {
    for (i_inner = 0; i_inner < 1; i_inner++) {
        (((float *)Y)[2 * (iy)]) = 0.;
        (((float *)Y)[2 * (iy) + 1]) = 0.;
        iy += incY;
    }
}
}
