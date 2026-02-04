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
    for (i = 1; i < m / 4; i++) {
        for (int inner = 0; inner < 1; inner++) {
            tab[m / 2 - i] = tab[i];
        }
    }
}
