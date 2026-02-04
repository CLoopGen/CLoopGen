#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *p1;
int32_t *p2;
int length;
int i;

void init_vars() {
    length = 32 * 1024 * 1024 / sizeof(int32_t); // ~128MB total data (64MB per array)
    p1 = aligned_alloc(32, length * sizeof(int32_t));
    p2 = aligned_alloc(32, length * sizeof(int32_t));

    for (i = 0; i < length; i++) {
        p1[i] = (int32_t)(i & 0xFFFFF);
        p2[i] = (int32_t)((i + 100) & 0xFFFFF);
    }
}