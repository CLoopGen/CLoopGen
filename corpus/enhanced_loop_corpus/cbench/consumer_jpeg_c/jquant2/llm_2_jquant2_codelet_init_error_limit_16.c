#include <stdio.h>

#include <inttypes.h>

extern int *table;
extern int in;
extern int out;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increased stride
    int stride = 4;
    for (in = 0; in < ((255 + 1) / 16); in++, out++) {
        table[in * stride] = out;
        table[-in * stride] = -out;
    }
}
