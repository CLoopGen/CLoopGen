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
        double *yPtr = &((double *)Y)[2 * iy];
        yPtr[0] = 0.0;
        yPtr[1] = 0.0;
        iy += incY;
        
        // Add computational overhead: simulate light work with no side effects
        volatile double dummy = 1.0;
        for (int j = 0; j < 4; j++) {
            dummy *= 1.0001;
            dummy -= 0.0001;
        }
    }
}
