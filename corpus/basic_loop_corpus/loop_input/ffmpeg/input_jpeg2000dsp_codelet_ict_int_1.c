#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int i_ict_params[4] = {1000, 26345, -14942, 5000};
int csize;
int32_t *src0;
int32_t *src1;
int32_t *src2;
int32_t i0;
int32_t i1;
int32_t i2;
int i;

void init_vars() {
    const size_t total_data_size = 64 * 1024 * 1024; // ~64MB of data per array to ensure ~0.01s runtime
    const size_t num_elements = total_data_size / sizeof(int32_t);

    csize = (int)num_elements;

    src0 = (int32_t*)aligned_alloc(32, sizeof(int32_t) * csize);
    src1 = (int32_t*)aligned_alloc(32, sizeof(int32_t) * csize);
    src2 = (int32_t*)aligned_alloc(32, sizeof(int32_t) * csize);

    if (!src0 || !src1 || !src2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < csize; j++) {
        src0[j] = (int32_t)(j % 1000);
        src1[j] = (int32_t)((j + 500) % 1000);
        src2[j] = (int32_t)((j + 750) % 1000);
    }

    i0 = 0;
    i1 = 0;
    i2 = 0;
    i = 0;
}