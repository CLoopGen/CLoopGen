#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    if (m > 4) {
        int i = 1;
        for (; i < m / 4; i += 2) {
            tab[m / 2 - i] = tab[i];
            if (i + 1 < m / 4) {
                tab[m / 2 - (i + 1)] = tab[i + 1];
            }
        }
    }
}
