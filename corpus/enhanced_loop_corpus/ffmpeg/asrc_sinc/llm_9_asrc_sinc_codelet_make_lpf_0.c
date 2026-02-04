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
    // Variant 2: Reduced trip count and simplified condition with decreased computational load
    if (dc_norm && num_taps > 0) {
        float inv = scale / sum;
        int step = 2; // Process every second element
        for (i = 0; i < num_taps; i += step) {
            h[i] *= inv;
        }
    }
}
