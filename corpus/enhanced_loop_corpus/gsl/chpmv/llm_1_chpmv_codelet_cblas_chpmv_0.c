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
int i;
if (N > 0) {
    for (i = 0; i < N; i += 2) {
        int upper = (i + 1 < N) ? i + 2 : i + 1;
        for (; i < upper; i++) {
            (((float *)Y)[2 * (iy)]) = 0.;
            (((float *)Y)[2 * (iy) + 1]) = 0.;
            iy += incY;
        }
        i--; // Compensate for outer loop increment
    }
}
}
