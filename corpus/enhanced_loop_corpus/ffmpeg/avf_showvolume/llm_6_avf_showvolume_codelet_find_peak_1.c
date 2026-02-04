#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *src;
extern int nb_samples;
extern float *peak;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float local_peak = *peak;
    for (i = 0; i < nb_samples; i++) {
        float abs_val = src[i] >= 0 ? src[i] : -src[i];
        if (abs_val > local_peak) {
            local_peak = abs_val;
        }
    }
    *peak = local_peak;
}
