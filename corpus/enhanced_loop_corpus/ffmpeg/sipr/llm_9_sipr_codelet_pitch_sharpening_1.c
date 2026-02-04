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
for (i = pitch_lag_int; i < 32; i++) {
    float temp1 = beta * fixed_vector[i - pitch_lag_int];
    float temp2 = beta * fixed_vector[i - pitch_lag_int] * 0.5f;
    fixed_vector[i] += temp1 + temp2;
}
}
