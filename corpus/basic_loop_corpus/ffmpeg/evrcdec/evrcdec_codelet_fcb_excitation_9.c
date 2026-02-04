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
for (i = pitch_lag; i < subframe_size; i++)
    excitation[i] += pitch_gain * excitation[i - pitch_lag];

}
