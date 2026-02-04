#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double *data;
extern size_t N;
extern size_t i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    size_t temp = 0;
    for (i = 0; i < N; i++) {
        temp += i;          // Remove direct assignment, accumulate in local variable
        data[i] = temp;     // WAW hazard possible if parallelized, but sequential semantics preserved
    }
    // Introduces intra-loop accumulation (loop-carried dependency via 'temp')
}
