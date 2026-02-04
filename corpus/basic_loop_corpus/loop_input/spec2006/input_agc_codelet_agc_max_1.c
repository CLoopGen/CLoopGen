#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

typedef int int32;
typedef float float32;

float32 maxc0 = 1.5f;
int32 n_frame = 65536; // Approximately 256MB / (4 bytes per float * 2 dimensions) ~ 32k, adjusted for single column access
int32 i;

float **mfc;

void init_vars() {
    mfc = (float**)calloc(n_frame, sizeof(float*));
    if (!mfc) {
        fprintf(stderr, "Failed to allocate mfc\n");
        exit(1);
    }

    for (int i = 0; i < n_frame; i++) {
        mfc[i] = (float*)malloc(1 * sizeof(float)); // Only one element per row is accessed: [0]
        if (!mfc[i]) {
            fprintf(stderr, "Failed to allocate mfc[%d]\n", i);
            exit(1);
        }
        mfc[i][0] = 10.0f + (float)i; // Arbitrary initial values
    }
}