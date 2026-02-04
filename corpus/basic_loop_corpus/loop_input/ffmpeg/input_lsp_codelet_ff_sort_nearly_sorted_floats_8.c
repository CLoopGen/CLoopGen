#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *vals;
int len = 65536; // Size chosen to take ~0.01s on modern CPU
int i;
int j;

void init_vars() {
    vals = (float*)aligned_alloc(32, len * sizeof(float));
    if (!vals) {
        exit(1);
    }

    // Initialize with reverse-sorted data to trigger worst-case sorting behavior
    for (int idx = 0; idx < len; idx++) {
        vals[idx] = (float)(len - idx);
    }
}