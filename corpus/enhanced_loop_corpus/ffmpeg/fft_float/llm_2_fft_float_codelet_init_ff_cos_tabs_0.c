#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int i;
extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with increasing stride
    for (i = 1; i < m / 4; i++) {
        int index = i * 2; // Stride of 2
        if (index < m / 4) {
            tab[m / 2 - index] = tab[index];
        }
    }
}
