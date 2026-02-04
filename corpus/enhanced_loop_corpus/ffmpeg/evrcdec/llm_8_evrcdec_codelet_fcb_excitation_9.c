#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *excitation;
extern float pitch_gain;
extern int pitch_lag;
extern int subframe_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Increased computational intensity with unrolled loop (2x unrolling) and additional arithmetic
    // Trip count effectively halved due to unrolling, but more operations per iteration
    int i;
    for (i = pitch_lag; i < subframe_size - 1; i += 2) {
        excitation[i]     += pitch_gain * excitation[i - pitch_lag];
        excitation[i + 1] += pitch_gain * excitation[i + 1 - pitch_lag];
        // Additional damping factor applied as extra computation
        excitation[i]     *= 0.99f;
        excitation[i + 1] *= 0.99f;
    }
    // Handle remaining element if subframe_size is odd
    if (i < subframe_size) {
        excitation[i] += pitch_gain * excitation[i - pitch_lag];
        excitation[i] *= 0.99f;
    }
}
