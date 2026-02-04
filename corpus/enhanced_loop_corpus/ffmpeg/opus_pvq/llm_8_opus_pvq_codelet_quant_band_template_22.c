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
    for (i = 0; i < N; i += 2) {
        if (i + 1 < N) {
            lowband_scratch[i] = lowband[i] * 1.5f;
            lowband_scratch[i + 1] = lowband[i + 1] * 1.5f;
        } else {
            lowband_scratch[i] = lowband[i] * 1.5f;
        }
    }
}
