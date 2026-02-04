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
        if (tab[i] >= 0.0f) {
            tab[m / 2 - i] = tab[i];
        } else {
            tab[m / 2 - i] = -tab[i];
        }
    }
}
