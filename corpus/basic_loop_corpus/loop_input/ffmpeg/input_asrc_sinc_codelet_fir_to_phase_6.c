#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *work;
int i;
int work_len;

void init_vars() {
    work_len = 67108864; // ~256MB / sizeof(float) ≈ 67M elements
    work = (float*)aligned_alloc(32, work_len * sizeof(float));
    if (!work) {
        exit(1);
    }
    for (int idx = 0; idx < work_len; idx++) {
        work[idx] = 1.0f;
    }
    i = 0;
}