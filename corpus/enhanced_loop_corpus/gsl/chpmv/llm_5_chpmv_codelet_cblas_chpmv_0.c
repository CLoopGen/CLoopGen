#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern void *Y;
extern  int incY;
extern int i;
extern int iy;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        (((float *)Y)[2 * (iy)]) = 0.;
        if (i % 2 == 0) {
            (((float *)Y)[2 * (iy) + 1]) = 0.;
        } else {
            (((float *)Y)[2 * (iy) + 1]) = 1.;
        }
        iy += incY;
    }
}
