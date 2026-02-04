#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int pitch_lag_int;
extern float beta;
extern float *fixed_vector;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    // This processes every second element in two passes to change access pattern
    for (i = pitch_lag_int; i < 48; i += 2)
        fixed_vector[i] += beta * fixed_vector[i - pitch_lag_int];
    for (i = pitch_lag_int + 1; i < 48; i += 2)
        fixed_vector[i] += beta * fixed_vector[i - pitch_lag_int];
}
