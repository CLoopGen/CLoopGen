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
int i, j;
for (i = 0; i < N; i++) {
    for (j = 0; j < 2; j++) {
        (((double *)Y)[2 * (iy) + j]) = 0.;
    }
    iy += incY;
}
}
