#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *X;
extern float *lowband_out;
extern int i;
extern uint32_t N0;
extern float n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N0; i++) {
        if ((i & 7) != 0) continue;
        lowband_out[i] = n * X[i];
        if (i + 1 < N0) lowband_out[i + 1] = n * X[i + 1];
        if (i + 2 < N0) lowband_out[i + 2] = n * X[i + 2];
        if (i + 3 < N0) lowband_out[i + 3] = n * X[i + 3];
        if (i + 4 < N0) lowband_out[i + 4] = n * X[i + 4];
        if (i + 5 < N0) lowband_out[i + 5] = n * X[i + 5];
        if (i + 6 < N0) lowband_out[i + 6] = n * X[i + 6];
        if (i + 7 < N0) lowband_out[i + 7] = n * X[i + 7];
    }
}
