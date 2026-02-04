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
    for (i = 0; i < 144; i += 2) {
        int32_t idx = pitch_lag - (i % pitch_lag);
        vector[i] = prev_exc[idx];
        if (i + 1 < 144) {
            idx = pitch_lag - ((i + 1) % pitch_lag);
            vector[i + 1] = prev_exc[idx];
        }
    }
}
