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
    float local_peak = 0.0f;
    for (i = 0; i < nb_samples; i++) {
        float val = src[i];
        float abs_val = val;
        if (val < 0) abs_val = -val;
        if (abs_val > local_peak) local_peak = abs_val;
    }
    if (local_peak > *peak) *peak = local_peak;
}
