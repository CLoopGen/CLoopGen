#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef double FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 2;
    int limit = m / 4;
    int mid = m / 2;
    for (int i = 1; i < limit; i += stride) {
        tab[mid - i] = tab[i];
        if (i + 1 < limit && mid - (i + 1) > i + 1) {
            tab[mid - (i + 1)] = tab[i + 1]; // Unroll-like effect with independent accesses, reducing loop-carried dependence
        }
    }
}
