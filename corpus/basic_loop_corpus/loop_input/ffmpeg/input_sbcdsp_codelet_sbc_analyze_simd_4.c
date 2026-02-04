#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int32_t *out;
unsigned int subbands;
int32_t t1[8];
int i;

void init_vars() {
    subbands = 8;
    out = (int32_t*)aligned_alloc(32, subbands * sizeof(int32_t));
    for (i = 0; i < subbands; i++) {
        t1[i] = (int32_t)(i * 1000);
        out[i] = 0;
    }
}