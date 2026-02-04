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
    // Variant 1: Strided memory access with reverse traversal and stride of 2
    // Access pattern: prev_exc[pitch_lag - i*2] with bounds check to stay within limits
    int32_t *vec = vector;
    int32_t *exc = prev_exc;
    int lag = pitch_lag;
    for (i = 0; i < 72; i += 2) {
        if ((lag - i) >= 0) {
            vec[i] = exc[lag - i];
        }
        if (i + 1 < 72 && (lag - (i + 1)) >= 0) {
            vec[i + 1] = exc[lag - (i + 1)];
        }
    }
}
