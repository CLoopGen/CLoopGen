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
    if (nb_samples > 0) {
        float abs_val = (src[0] >= 0) ? src[0] : -src[0];
        *peak = abs_val;
        for (i = 1; i < nb_samples; i++) { // Reduced effective work per iteration by handling first element outside
            float current_abs = (src[i] >= 0) ? src[i] : -src[i];
            *peak = (*peak > current_abs) ? *peak : current_abs;
        }
    }
}
