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
    for (i = 1; i < m / 4; i++) {
        tab[m / 2 - i] = tab[i];
        if (i + 1 < m / 4) {
            i++;
            tab[m / 2 - i] = tab[i];
        }
    }
}
