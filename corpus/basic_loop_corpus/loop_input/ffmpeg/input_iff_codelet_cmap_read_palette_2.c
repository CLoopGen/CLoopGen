#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint32_t *pal;
int count;
int i;

void init_vars() {
    count = 16777216; // 64 MB of data (16M * 4 bytes per uint32_t)
    pal = (uint32_t*)aligned_alloc(32, count * sizeof(uint32_t));
    if (!pal) {
        exit(1);
    }
    for (int j = 0; j < count; j++) {
        pal[j] = rand() | ((uint32_t)rand() << 16);
    }
}