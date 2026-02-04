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
    float *local_excitation = excitation;
    int local_pitch_lag = pitch_lag;
    int local_subframe_size = subframe_size;
    float local_pitch_gain = pitch_gain;
    for (i = local_pitch_lag; i < local_subframe_size; i++) {
        float temp = local_pitch_gain * local_excitation[i - local_pitch_lag];
        local_excitation[i] += temp;
    }
}
