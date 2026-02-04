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
    for (i = 0; i < 72; i += 2) {
        vector[i] = prev_exc[pitch_lag - i % pitch_lag];
        if (i + 1 < 72) {
            vector[i + 1] = prev_exc[pitch_lag - (i + 1) % pitch_lag];
        }
    }
}
