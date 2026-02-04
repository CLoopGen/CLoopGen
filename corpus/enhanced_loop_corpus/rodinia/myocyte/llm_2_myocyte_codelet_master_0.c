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
    // Variant 1: Strided memory access pattern with reverse iteration
    temp = temp % nthreads; // Ensure temp is within bounds
    for (i = 0; i < 4; i++) {
        int idx = (3 - i); // Reverse access: 3, 2, 1, 0
        if (temp >= nthreads) {
            temp = 0;
        }
        th_count[idx] = temp;
        temp++;
    }
}
