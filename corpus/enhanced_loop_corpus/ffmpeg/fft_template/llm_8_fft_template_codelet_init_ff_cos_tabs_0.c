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
    int j;
    for (i = 1; i < m / 4; i++) {
        j = m / 2 - i;
        tab[j] = tab[i] * 2.0f + 1.0f;
        tab[j-1] = tab[i] * 0.5f;
    }
}
