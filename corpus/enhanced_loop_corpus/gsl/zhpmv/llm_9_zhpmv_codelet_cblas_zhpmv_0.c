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
    for (i = 0; i < N * 2; i += 2) {  // Doubled trip count with step of 2
        int current_iy = iy + i * incY / 2;
        ((double *)Y)[2 * current_iy] = 0.0;
        ((double *)Y)[2 * current_iy + 1] = 0.0;
        if (i + 1 < N * 2) {
            int next_iy = current_iy + incY;
            ((double *)Y)[2 * next_iy] = 0.0;
            ((double *)Y)[2 * next_iy + 1] = 0.0;
        }
    }
}
