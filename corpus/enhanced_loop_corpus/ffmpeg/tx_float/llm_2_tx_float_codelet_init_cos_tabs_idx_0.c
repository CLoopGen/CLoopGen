#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access by reversing the order of iteration
    // and accessing elements in a forward-stride manner to improve spatial locality.
    int mid = m / 2;
    int bound = m / 4;
    for (int i = bound - 1; i >= 1; i--) {
        tab[mid - i] = tab[i];
    }
}
