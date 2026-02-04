#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int length = 1 << 20; // 1M elements, roughly 2MB of data (1M * 2B * 2 arrays)
int scaling = 8;
int64_t sum = 0;

int16_t *v1;
int16_t *v2;

void init_vars() {
    v1 = aligned_alloc(32, length * sizeof(int16_t));
    v2 = aligned_alloc(32, length * sizeof(int16_t));

    for (int i = 0; i < length; i++) {
        v1[i] = rand() % 512 - 256;
        v2[i] = rand() % 512 - 256;
    }
}