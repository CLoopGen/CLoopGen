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
    int step = m / 16;
    for (i = 1; i < m / 4; i++) {
        tab[m / 2 - i] = tab[i];
        tab[m / 2 - i - 1] = tab[i + 1];
        tab[m / 2 - i - 2] = tab[i + 2];
        tab[m / 2 - i - 3] = tab[i + 3];
    }
}
