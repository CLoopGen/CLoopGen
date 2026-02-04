#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 1; i < m / 4; i++) {
        tab[m / 2 - i] = tab[i] + tab[m / 2 - i - 1];
    }
}
