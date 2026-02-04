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
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < nb_samples; i += 2)
        *peak = ((*peak) > (((src[i]) >= 0 ? (src[i]) : (-(src[i])))) ? (*peak) : (((src[i]) >= 0 ? (src[i]) : (-(src[i])))));
}
