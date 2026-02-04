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
    int temp_val = iy;
    for (i = 0; i < lenY; i++) {
        int idx = 2 * temp_val;
        (((float *)Y)[idx]) = 0.;
        (((float *)Y)[idx + 1]) = 0.;
        temp_val += incY;
        iy = temp_val; // Introduce WAW dependency on iy, making it updated in each iteration and carried forward
    }
}
