#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *p;
int i0;
int i1;
int i;

void init_vars() {
    const size_t data_size = 64 * 1024 * 1024; // 64 MB of float data
    p = (float*)aligned_alloc(32, data_size);
    if (!p) exit(1);

    for (size_t idx = 0; idx < data_size / sizeof(float); idx++) {
        p[idx] = (float)(idx % 1000) / 10.0f;
    }

    i0 = 100;
    i1 = 1000;

    i = 0;
}