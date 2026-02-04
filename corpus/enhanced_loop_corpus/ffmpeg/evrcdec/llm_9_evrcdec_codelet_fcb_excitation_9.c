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
    // Variant 2: Reduced trip count with increased data dependency depth
    // Only process every 4th element, but use a longer feedback chain (increased effective lag)
    int i;
    int extended_lag = pitch_lag * 2;
    if (extended_lag >= subframe_size) return; // Avoid out-of-bounds
    for (i = extended_lag; i < subframe_size; i += 4) {
        // Use deeper history and accumulate over multiple prior contributions
        excitation[i] += pitch_gain * (
            excitation[i - extended_lag] +
            0.5f * excitation[i - extended_lag - 1]
        ) * 0.7f; // Additional scaling to simulate filtering
    }
}
