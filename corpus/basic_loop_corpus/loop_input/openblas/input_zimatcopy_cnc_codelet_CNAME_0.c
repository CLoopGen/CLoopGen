#include <stdio.h>
#include <stdlib.h>

typedef long BLASLONG;

BLASLONG rows = 1024;
BLASLONG cols = 512;
float alpha_r = 1.5f;
float alpha_i = 0.8f;
BLASLONG lda = 2048;
BLASLONG i;
BLASLONG j;
BLASLONG ia;
float *aptr;
float a0;
float a1;

static float *aptr_storage = NULL;

void init_vars() {
    const BLASLONG total_size = (rows * 2) * cols + lda * cols;
    aptr_storage = (float*)calloc(total_size, sizeof(float));
    if (!aptr_storage) {
        fprintf(stderr, "Failed to allocate memory\n");
        exit(1);
    }

    aptr = aptr_storage;

    for (BLASLONG col = 0; col < cols; col++) {
        float *col_start = aptr_storage + col * lda;
        for (BLASLONG row = 0; row < rows; row++) {
            col_start[2 * row] = (float)(row + 1);
            col_start[2 * row + 1] = (float)(-(row + 1));
        }
    }
}

__attribute__((destructor)) static void cleanup() {
    if (aptr_storage) {
        free(aptr_storage);
    }
}