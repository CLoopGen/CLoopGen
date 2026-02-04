#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int num_taps;
extern float scale;
extern int dc_norm;
extern int i;
extern float *h;
extern float sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; dc_norm && i < num_taps; i++) {
        if (i % 2 == 0) {
            h[i] *= scale / sum;
        } else {
            h[i] *= scale / sum;
        }
    }
}
