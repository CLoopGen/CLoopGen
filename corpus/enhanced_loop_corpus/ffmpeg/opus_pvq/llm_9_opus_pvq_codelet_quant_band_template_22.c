#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int N;
extern float *lowband;
extern float *lowband_scratch;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N * 2; i++) {
        int idx = i / 2;
        lowband_scratch[idx] = (lowband[idx] + lowband[idx] + lowband[idx]) / 3.0f;
    }
}
