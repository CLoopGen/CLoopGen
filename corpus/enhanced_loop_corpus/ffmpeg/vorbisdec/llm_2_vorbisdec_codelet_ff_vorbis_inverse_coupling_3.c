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
    // Variant 1: Strided memory access with stride of 2
    // This processes every second element in a forward pass, then a second pass for odd indices
    for (i = 0; i < blocksize; i += 2) {
        if (i + 1 < blocksize) {
            // Process even index i
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
            // Process next (odd) index i+1
            if (mag[i+1] > 0.) {
                if (ang[i+1] > 0.) {
                    ang[i+1] = mag[i+1] - ang[i+1];
                } else {
                    float temp = ang[i+1];
                    ang[i+1] = mag[i+1];
                    mag[i+1] += temp;
                }
            } else {
                if (ang[i+1] > 0.) {
                    ang[i+1] += mag[i+1];
                } else {
                    float temp = ang[i+1];
                    ang[i+1] = mag[i+1];
                    mag[i+1] -= temp;
                }
            }
        } else {
            // Handle last element if blocksize is odd
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
}
