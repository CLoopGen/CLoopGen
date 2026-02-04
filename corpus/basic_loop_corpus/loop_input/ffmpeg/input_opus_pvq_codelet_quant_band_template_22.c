#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int N;
float *lowband;
float *lowband_scratch;
int i;

void init_vars() {
    N = 67108864; // Approximately 256MB of data (67M * sizeof(float) ≈ 256MB)

    lowband = (float*)aligned_alloc(32, N * sizeof(float));
    lowband_scratch = (float*)aligned_alloc(32, N * sizeof(float));

    if (!lowband || !lowband_scratch) {
        exit(1);
    }

    for (int j = 0; j < N; j++) {
        lowband[j] = (float)(j % 1000) + 0.5f;
    }
}