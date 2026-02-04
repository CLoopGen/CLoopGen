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
    int j;
    for (j = pitch_lag_int; j < 48; j++) {
        fixed_vector[j] = beta * fixed_vector[j - pitch_lag_int] + fixed_vector[j];
    }
}
