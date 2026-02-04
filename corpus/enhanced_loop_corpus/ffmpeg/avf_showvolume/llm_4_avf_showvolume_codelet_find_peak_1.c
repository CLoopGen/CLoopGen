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
    for (i = 0; i < nb_samples; i++) {
        float abs_val = src[i];
        if (abs_val < 0) abs_val = -abs_val;
        if (abs_val > *peak) {
            *peak = abs_val;
        }
    }
}
