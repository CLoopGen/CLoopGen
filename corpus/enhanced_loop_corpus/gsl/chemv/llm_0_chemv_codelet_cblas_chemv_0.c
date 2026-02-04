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
int j;
for (j = 0; j < N; j++) {
    for (i = 0; i < 1; i++) {
        (((float *)Y)[2 * (iy)]) = 0.;
        (((float *)Y)[2 * (iy) + 1]) = 0.;
        iy += incY;
    }
}
}
