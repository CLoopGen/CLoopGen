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
    int mag_pos = (m > 0.0);
    int ang_pos = (a > 0.0);

    if (mag_pos && ang_pos) {
        ang[i] = m - a;
    } else if (mag_pos) {
        ang[i] = m;
        mag[i] += a;
    } else if (ang_pos) {
        ang[i] += m;
    } else {
        ang[i] = m;
        mag[i] -= a;
    }
}
}
