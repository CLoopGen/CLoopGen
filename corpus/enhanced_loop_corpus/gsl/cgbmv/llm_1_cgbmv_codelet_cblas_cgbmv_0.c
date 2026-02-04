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
for (i = 0; i < lenY; i++) {
    int j;
    for (j = 0; j < 2; j++) {
        if (j == 0) {
            (((float *)Y)[2 * (iy)]) = 0.;
        } else {
            (((float *)Y)[2 * (iy) + 1]) = 0.;
        }
    }
    iy += incY;
}
}
