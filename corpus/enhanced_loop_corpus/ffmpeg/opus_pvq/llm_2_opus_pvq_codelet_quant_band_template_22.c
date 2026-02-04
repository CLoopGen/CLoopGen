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
    int stride = 2;
    for (i = 0; i < N; i += stride) {
        if (i + 1 < N) {
            lowband_scratch[i] = lowband[i];
            lowband_scratch[i + 1] = lowband[i + 1];
        } else {
            lowband_scratch[i] = lowband[i];
        }
    }
}
