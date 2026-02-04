#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int i;
extern int q;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size 2 (accessing even indices only)
    for (i = 0; i < 8; i += 2) {
        q -= table[i];
        if (q < 0)
            break;
    }
}
