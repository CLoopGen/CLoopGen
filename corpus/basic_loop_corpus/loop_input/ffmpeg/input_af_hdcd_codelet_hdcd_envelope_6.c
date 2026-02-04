#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *samples;
int count;
int stride;
int i;
int shft;

void init_vars() {
    count = 65536;
    stride = 1;
    shft = 1;
    samples = aligned_alloc(32, count * stride * sizeof(int32_t));
    for (int j = 0; j < count * stride; j++) {
        samples[j] = rand();
    }
}