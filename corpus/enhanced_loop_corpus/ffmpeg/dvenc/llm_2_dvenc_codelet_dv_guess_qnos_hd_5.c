#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int qlevels[5];
extern int i;
extern int largest;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2, wrapping around using modulo)
    for (i = 0; i < 5; i++) {
        int idx = (i * 2) % 5; // Strided access pattern: 0, 2, 4, 1, 3
        if (qlevels[idx] < qlevels[largest])
            largest = idx;
    }
}
