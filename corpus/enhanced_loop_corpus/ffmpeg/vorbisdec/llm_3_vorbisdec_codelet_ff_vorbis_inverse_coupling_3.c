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
    // Variant 2: Reverse consecutive memory access
    // Iterates from the end of the array to the beginning
    for (i = blocksize - 1; i >= 0; i--) {
        if (mag[i] > 0.) {
            if (ang[i] > 0.) {
                ang[i] = mag[i] - ang[i];
            } else {
                float temp = ang[i];
                ang[i] = mag[i];
                mag[i] += temp;
            }
        } else {
            if (ang[i] > 0.) {
                ang[i] += mag[i];
            } else {
                float temp = ang[i];
                ang[i] = mag[i];
                mag[i] -= temp;
            }
        }
    }
}
