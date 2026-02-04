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
    int base_idx = 2 * iy;
    ((double *)Y)[base_idx] = 0.0;
    ((double *)Y)[base_idx + 1] = 0.0;
    ((double *)Y)[base_idx + 2] = 0.0;
    ((double *)Y)[base_idx + 3] = 0.0;
    iy += incY;
}
}
