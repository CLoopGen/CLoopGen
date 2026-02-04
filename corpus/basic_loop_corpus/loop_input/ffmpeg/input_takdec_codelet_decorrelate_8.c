#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int length = 65536;
int32_t *p1;
int32_t *p2;
int i;
int length2 = 16384;
int order_half = 8192;

void init_vars() {
    p1 = (int32_t*)aligned_alloc(32, length * sizeof(int32_t));
    p2 = (int32_t*)aligned_alloc(32, length * sizeof(int32_t));

    for (int idx = 0; idx < length; idx++) {
        p1[idx] = rand() % 1000;
        p2[idx] = rand() % 1000;
    }
}