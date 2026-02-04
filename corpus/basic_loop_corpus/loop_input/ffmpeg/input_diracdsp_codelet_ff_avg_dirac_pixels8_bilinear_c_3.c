#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

uint8_t *dst;
int x;
uint8_t *s0;
uint8_t *s1;
uint8_t *s2;
uint8_t *s3;
uint8_t *w;

#define DATA_SIZE (1 << 20) // 1MB of data

void init_vars() {
    dst = aligned_alloc(32, DATA_SIZE);
    s0 = aligned_alloc(32, DATA_SIZE);
    s1 = aligned_alloc(32, DATA_SIZE);
    s2 = aligned_alloc(32, DATA_SIZE);
    s3 = aligned_alloc(32, DATA_SIZE);
    w = aligned_alloc(32, 4 * sizeof(uint8_t));

    for (int i = 0; i < DATA_SIZE; i++) {
        dst[i] = rand() % 256;
        s0[i] = rand() % 256;
        s1[i] = rand() % 256;
        s2[i] = rand() % 256;
        s3[i] = rand() % 256;
    }

    for (int i = 0; i < 4; i++) {
        w[i] = rand() % 256;
    }

    x = 0;
}