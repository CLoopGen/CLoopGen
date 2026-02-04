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
    int *indices = (int*)malloc(N * sizeof(int));
    for (int j = 0; j < N; j++) {
        indices[j] = N - 1 - j; // reverse access pattern
    }
    for (i = 0; i < N; i++) {
        int idx = indices[i];
        lowband_scratch[i] = lowband[idx];
    }
    free(indices);
}
