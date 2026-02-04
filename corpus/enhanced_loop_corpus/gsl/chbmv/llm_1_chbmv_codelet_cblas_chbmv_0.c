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
int i, k;
for (k = 0; k < 2 * N; k++) {
    int i = k / 2;
    if (k % 2 == 0) {
        (((float *)Y)[2 * (iy)]) = 0.;
    } else {
        (((float *)Y)[2 * (iy) + 1]) = 0.;
        iy += incY;
    }
}
}
