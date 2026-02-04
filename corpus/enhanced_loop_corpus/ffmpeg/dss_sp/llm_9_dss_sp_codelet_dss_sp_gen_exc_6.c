#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int32_t *vector;
extern int32_t *prev_exc;
extern int pitch_lag;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int32_t base = pitch_lag;
    for (i = 0; i < 36; i++) {
        vector[2*i]     = prev_exc[base - (i % pitch_lag)];
        vector[2*i + 1] = prev_exc[base - ((i + 18) % pitch_lag)];
        vector[2*i + 36] = prev_exc[base - ((i + 36) % pitch_lag)];
        vector[2*i + 37] = prev_exc[base - ((i + 54) % pitch_lag)];
    }
}
