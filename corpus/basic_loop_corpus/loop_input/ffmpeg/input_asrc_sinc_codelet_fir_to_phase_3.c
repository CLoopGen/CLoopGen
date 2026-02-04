#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *work;
int i;
int work_len;

void init_vars() {
    work_len = 67108864; // ~256 MB / sizeof(float) ≈ 67M elements
    work = (float *)aligned_alloc(32, work_len * sizeof(float));
    if (!work) {
        exit(1);
    }
    for (int j = 0; j < work_len; j++) {
        work[j] = 1.0f;
    }
    i = 0;
}