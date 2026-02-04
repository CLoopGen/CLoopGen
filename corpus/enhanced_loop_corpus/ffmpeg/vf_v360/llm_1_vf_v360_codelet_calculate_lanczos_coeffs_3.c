#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *coeffs;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 2; i++) {
        for (int k = 0; k < 2; k++) {
            int idx = i * 2 + k;
            coeffs[idx] /= sum;
        }
    }
}
