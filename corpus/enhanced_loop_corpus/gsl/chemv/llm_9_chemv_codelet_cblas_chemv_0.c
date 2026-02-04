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
for (i = 0; i < N * 2; i++) {
    int offset = (i % 2 == 0) ? 0 : 1;
    (((float *)Y)[2 * (iy) + offset]) = 0.;
    if (offset == 1) {
        iy += incY;
    }
}
}
