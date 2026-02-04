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
    for (i = 1; i < m / 4 && (m / 2 - i) >= 0; i++) {
        if (i % 2 == 0) {
            tab[m / 2 - i] = tab[i];
        }
    }
}
