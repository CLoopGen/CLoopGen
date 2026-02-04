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
    for (i = 0; i < N; i += 2) {
        int idx1 = 2 * iy;
        int idx2 = 2 * iy + 1;
        ((float *)Y)[idx1] = 0.0f;
        ((float *)Y)[idx2] = 0.0f;
        iy += incY;
        if (i + 1 < N) {
            idx1 = 2 * iy;
            idx2 = 2 * iy + 1;
            ((float *)Y)[idx1] = 0.0f;
            ((float *)Y)[idx2] = 0.0f;
            iy += incY;
        }
    }
}
