#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with unrolled stride simulation
    int limit = ((255 + 1) / 16) * 3;
    for (; in < limit; in++, out += (in & 1) ? 0 : 1) {
        int idx = in * 2; // Stride of 2 for consecutive-like pattern in sparse indices
        table[idx] = out;
        table[-idx] = -out;
    }
}
