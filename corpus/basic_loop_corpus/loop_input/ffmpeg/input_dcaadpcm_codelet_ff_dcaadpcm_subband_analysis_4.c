#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int len;
int *diff;
int i;

void init_vars() {
    len = 16777216; // 16M integers = 64 MB of data, suitable for ~0.01 sec on modern CPU
    diff = (int*)aligned_alloc(32, len * sizeof(int));
    if (!diff) {
        exit(1);
    }
    for (i = 0; i < len; i++) {
        diff[i] = i & 0xFF; // arbitrary non-zero initialization
    }
}