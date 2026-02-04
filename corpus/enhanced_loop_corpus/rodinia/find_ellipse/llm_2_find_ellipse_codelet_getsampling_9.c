#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern int *bindex;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (step of 2)
    for (i = 0; i < N; i += 2) {
        if (i < N) bindex[i] = i;
    }
}
