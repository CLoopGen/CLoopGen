#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *speech;
int subframe_size;
int temp;
int i;

void init_vars() {
    subframe_size = 1 << 17;  // 128k elements, ~256KB of data
    speech = (int16_t *)aligned_alloc(32, subframe_size * sizeof(int16_t));
    temp = 12345;  // arbitrary non-zero value to ensure meaningful computation

    for (int j = 0; j < subframe_size; j++) {
        speech[j] = (int16_t)(j % 32768);
    }
}