#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int bd_sequence[8];
extern double a_work[8];
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element in a_work and bd_sequence, unrolled-like pattern)
    for (k = 0; k < 7; k += 2) {
        if (k + 1 < 7) {
            a_work[k + 1] = a_work[k] + bd_sequence[k + 1];
        }
        if (k + 2 < 8) {
            a_work[k + 2] = a_work[k + 1] + bd_sequence[k + 2];
        }
    }
}
