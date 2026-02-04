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
    // Variant 2: Consecutive forward memory access using a pointer increment
    // Rewritten to traverse both arrays in increasing index order
    int32_t *vec = vector;
    int32_t *exc = prev_exc + pitch_lag - 71; // point to start of relevant segment
    for (i = 0; i < 72; i++) {
        vec[i] = exc[i]; // now consecutive forward access
    }
}
