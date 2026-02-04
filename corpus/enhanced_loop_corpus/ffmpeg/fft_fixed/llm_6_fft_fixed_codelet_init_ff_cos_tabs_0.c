#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int16_t FFTSample;

extern int i;
extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int j;
    for (j = 1; j < m / 4; j++) {
        tab[m / 2 - j] = tab[j];
        tab[m / 2 + j] = tab[m / 2 - j]; // Introduces WAW and RAW dependency: write after write and read after write on tab[m/2-j]
    }
}
