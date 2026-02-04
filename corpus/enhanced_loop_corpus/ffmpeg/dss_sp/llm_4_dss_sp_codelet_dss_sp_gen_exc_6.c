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
    for (i = 0; i < 72; i++) {
        int32_t index = pitch_lag - (i % pitch_lag);
        if (index >= 0) {
            vector[i] = prev_exc[index];
        }
    }
}
