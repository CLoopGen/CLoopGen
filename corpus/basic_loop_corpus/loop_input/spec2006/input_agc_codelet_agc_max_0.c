#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <time.h>

typedef int int32;
typedef float float32;

float32 maxc0;
int32 n_frame;
int32 i;

float **mfc;

void init_vars() {
    n_frame = 1 << 20; // Approximately 1M frames, adjust for ~0.01s runtime
    maxc0 = -__FLT_MAX__;

    mfc = (float**)calloc(n_frame, sizeof(float*));
    if (!mfc) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    srand(time(NULL));
    for (int32 idx = 0; idx < n_frame; idx++) {
        mfc[idx] = (float*)malloc(1 * sizeof(float)); // Only allocate column 0
        if (!mfc[idx]) {
            fprintf(stderr, "Allocation failed\n");
            exit(1);
        }
        mfc[idx][0] = (float32)(rand()) / RAND_MAX * 2.0f * __FLT_MAX__ - __FLT_MAX__;
    }
}