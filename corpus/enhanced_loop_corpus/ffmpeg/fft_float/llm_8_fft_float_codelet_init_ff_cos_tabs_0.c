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
    int step = 2;
    for (i = 1; i < m / 4; i += step) {
        tab[m / 2 - i] = tab[i];
        if (i + 1 < m / 4) {
            tab[m / 2 - (i + 1)] = tab[i + 1];
        }
    }
}
