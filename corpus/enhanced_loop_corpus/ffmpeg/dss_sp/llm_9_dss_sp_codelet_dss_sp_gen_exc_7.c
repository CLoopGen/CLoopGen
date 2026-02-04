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
    int32_t offset = pitch_lag;
    for (i = 0; i < 36; i++) {
        vector[i]             = prev_exc[offset - i];
        vector[i + 36]         = prev_exc[offset - i - 36];
    }
}
