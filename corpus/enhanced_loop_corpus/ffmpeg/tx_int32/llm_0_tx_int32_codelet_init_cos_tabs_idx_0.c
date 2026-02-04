#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int32_t FFTSample;

extern int m;
extern FFTSample *tab;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int j = 0; j < 2; j++) {
        for (int i = 1; i < m / 4; i++) {
            if (j == 0) {
                tab[m / 2 - i] = tab[i];
            }
        }
    }
}
