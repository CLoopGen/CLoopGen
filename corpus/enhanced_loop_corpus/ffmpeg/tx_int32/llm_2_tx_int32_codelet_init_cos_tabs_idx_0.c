#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with step size of 2
    // Instead of consecutive indices, we access every second element
    int step = 2;
    for (int i = 1; i < m / 4; i += step) {
        if (i < m / 4) {
            tab[m / 2 - i] = tab[i];
        }
    }
}
