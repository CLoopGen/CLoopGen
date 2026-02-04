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
    // Variant 2: Consecutive backward memory access using offset indexing
    int start = m / 4 - 1;
    for (i = 0; i < m / 4 - 1; i++) {
        int forward_idx = start - i; // Traverse backwards consecutively
        tab[m / 2 - forward_idx] = tab[forward_idx];
    }
}
