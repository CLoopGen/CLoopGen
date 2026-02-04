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
    if (dc_norm) {
        for (i = 0; i < num_taps; i++) {
            h[i] *= scale / sum;
        }
    } else {
        for (i = 0; i < num_taps; i++);
    }
}
