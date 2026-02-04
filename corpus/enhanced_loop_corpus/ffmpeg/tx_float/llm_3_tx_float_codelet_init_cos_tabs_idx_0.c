#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided memory access with step size of 2, processing only even indices
    // within the valid range, thus modifying access pattern to non-consecutive locations.
    int mid = m / 2;
    int bound = m / 4;
    for (int i = 1; i < bound; i += 2) {
        tab[mid - i] = tab[i];
    }
}
