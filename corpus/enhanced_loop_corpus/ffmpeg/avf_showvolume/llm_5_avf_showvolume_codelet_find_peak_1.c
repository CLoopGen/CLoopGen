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
        float val = src[i];
        float abs_val = val >= 0 ? val : -val;
        *peak = (*peak >= abs_val) ? *peak : abs_val;
    }
}
