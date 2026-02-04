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
    for (i = 1; i < m / 8; i++) {
        FFTSample temp1 = tab[i];
        FFTSample temp2 = tab[2*i];
        tab[m / 2 - i] = temp1;
        tab[m / 2 - 2*i] = temp2;
    }
}
