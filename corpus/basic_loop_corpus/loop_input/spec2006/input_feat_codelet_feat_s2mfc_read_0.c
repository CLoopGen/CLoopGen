#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef float float32;
typedef int int32;

float32 **mfc;
int32 n_float32;
int32 i;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64 MB for sufficient runtime (~0.01 sec estimate)
    n_float32 = total_data_size / sizeof(float32);

    mfc = (float32**)calloc(1, sizeof(float32*));
    if (!mfc) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    mfc[0] = (float32*)malloc(n_float32 * sizeof(float32));
    if (!mfc[0]) {
        fprintf(stderr, "Allocation failed\n");
        free(mfc);
        exit(1);
    }

    // Initialize with non-zero pattern to ensure bit manipulation has effect
    for (int32 j = 0; j < n_float32; j++) {
        uint32_t pattern = (j * 177161) & 0xFFFFFFFFU;
        memcpy(&mfc[0][j], &pattern, sizeof(float32));
    }
}