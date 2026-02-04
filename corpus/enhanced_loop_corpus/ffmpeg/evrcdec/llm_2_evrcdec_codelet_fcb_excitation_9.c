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
    // Variant 1: Strided memory access with stride of 2
    // Processes only even or odd indices depending on initial offset
    // Ensures bounds are respected by adjusting loop limit
    int start = (pitch_lag % 2 == 0) ? pitch_lag : pitch_lag + 1;
    for (i = start; i < subframe_size; i += 2)
        excitation[i] += pitch_gain * excitation[i - pitch_lag];
}
