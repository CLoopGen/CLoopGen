#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int nthreads;
extern int th_count[4];
extern int temp;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (wrapping around using modulo)
    int stride = 2;
    for (i = 0; i < 4; i += stride) {
        int idx = i % 4;  // Ensure index remains within bounds
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[idx] = temp;
        temp = temp + 1;
    }
    // Handle remaining elements not covered by strided access
    for (i = 1; i < 4; i += stride) {
        int idx = i % 4;
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[idx] = temp;
        temp = temp + 1;
    }
}
