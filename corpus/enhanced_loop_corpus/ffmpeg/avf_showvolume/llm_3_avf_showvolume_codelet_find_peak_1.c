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
    // Variant 2: Reverse consecutive memory access
    for (i = nb_samples - 1; i >= 0; i--)
        *peak = ((*peak) > (((src[i]) >= 0 ? (src[i]) : (-(src[i])))) ? (*peak) : (((src[i]) >= 0 ? (src[i]) : (-(src[i])))));
}
