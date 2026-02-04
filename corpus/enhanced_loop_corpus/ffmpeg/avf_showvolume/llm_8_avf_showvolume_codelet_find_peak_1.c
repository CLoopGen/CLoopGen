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
    int j;
    for (i = 0; i < nb_samples; i += 2) {
        float abs_val1 = src[i] >= 0 ? src[i] : -src[i];
        *peak = (*peak > abs_val1) ? *peak : abs_val1;
        
        if (i + 1 < nb_samples) {
            float abs_val2 = src[i+1] >= 0 ? src[i+1] : -src[i+1];
            *peak = (*peak > abs_val2) ? *peak : abs_val2;
        }
    }
}
