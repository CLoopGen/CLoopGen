#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *mag;
extern float *ang;
extern intptr_t blocksize;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < blocksize; i++) {
    float m = mag[i];
    float a = ang[i];

    if (!(m > 0.)) {
        if (a > 0.) {
            ang[i] += m;
            continue;
        } else {
            float temp = a;
            ang[i] = m;
            mag[i] -= temp;
            continue;
        }
    }

    if (a > 0.) {
        ang[i] = m - a;
    } else {
        ang[i] = m;
        mag[i] += a;
    }
}
}
