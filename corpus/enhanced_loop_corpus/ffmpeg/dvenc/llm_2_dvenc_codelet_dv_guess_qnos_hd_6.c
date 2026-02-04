#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int min_qlevel[5];
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every second element, then handle remainder)
    // We'll process indices in a strided manner: first even, then odd indices
    int stride = 2;
    for (i = 0; i < 5; i += stride) {
        if (qlevels[i] > min_qlevel[i] && qlevels[i] > qlevels[largest])
            largest = i;
    }
    for (i = 1; i < 5; i += stride) {
        if (qlevels[i] > min_qlevel[i] && qlevels[i] > qlevels[largest])
            largest = i;
    }
}
