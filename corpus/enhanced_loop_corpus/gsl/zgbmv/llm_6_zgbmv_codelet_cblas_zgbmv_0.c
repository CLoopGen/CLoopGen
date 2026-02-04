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
    int idx = 2 * iy;
    for (i = 0; i < lenY; i++) {
        ((double *)Y)[idx] = 0.;
        ((double *)Y)[idx + 1] = 0.;
        idx += 2 * incY;
    }
}
