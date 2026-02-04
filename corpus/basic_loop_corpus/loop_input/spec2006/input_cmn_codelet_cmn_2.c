#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 *cmn_mean;
int32 n_frame;
int32 veclen;
int32 i;

void init_vars() {
    veclen = 1 << 24; // ~16.7 million elements, ~64 MB for float32
    n_frame = 1000;
    
    cmn_mean = (float32*)aligned_alloc(32, veclen * sizeof(float32));
    
    if (!cmn_mean) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int32 j = 0; j < veclen; j++) {
        cmn_mean[j] = (float32)(j % 1000) + 1.0f;
    }
}