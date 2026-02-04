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
    if (pitch_lag_int >= 48) return;
    for (i = pitch_lag_int; i < 48; i++) {
        fixed_vector[i] += beta * fixed_vector[i - pitch_lag_int];
    }
}
