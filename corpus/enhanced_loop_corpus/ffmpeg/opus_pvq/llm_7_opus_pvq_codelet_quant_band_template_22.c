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
    for (i = 1; i < N; i++)
        lowband_scratch[i-1] = lowband[i];
    if (N > 0)
        lowband_scratch[N-1] = lowband[0];
}
