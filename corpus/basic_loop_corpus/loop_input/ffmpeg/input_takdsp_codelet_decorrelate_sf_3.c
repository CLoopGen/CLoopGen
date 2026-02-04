#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <time.h>

int32_t *p1;
int32_t *p2;
int length;
int dshift;
int dfactor;
int i;

void init_vars() {
    const size_t target_bytes = 64 * 1024 * 1024; // Aim for ~64 MB of total data
    const size_t element_size = sizeof(int32_t);
    length = target_bytes / (2 * element_size); // Two arrays: p1 and p2

    p1 = aligned_alloc(32, length * element_size);
    p2 = aligned_alloc(32, length * element_size);

    if (!p1 || !p2) {
        fprintf(stderr, "Allocation failed\n");
        exit(1);
    }

    for (int j = 0; j < length; j++) {
        p1[j] = rand() & 0xFFFFF;
        p2[j] = rand() & 0xFFFFF;
    }

    dshift = 4;
    dfactor = 257;
    i = 0;
}