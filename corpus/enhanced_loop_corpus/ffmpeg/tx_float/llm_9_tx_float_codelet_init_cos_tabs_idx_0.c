#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 2; i < m / 4; i += 2) {
        FFTSample temp1 = tab[i];
        FFTSample temp2 = tab[i + 1];
        tab[m / 2 - i] = temp1;
        if (i + 1 < m / 4) {
            tab[m / 2 - (i + 1)] = temp2;
        }
    }
}
