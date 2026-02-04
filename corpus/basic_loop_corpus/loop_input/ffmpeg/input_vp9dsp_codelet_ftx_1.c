#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

int16_t *buf;
int sz;
int bit_depth;
double ind[1024];
int n;

void init_vars() {
    bit_depth = 16; 
    sz = 32; 

    buf = (int16_t*)aligned_alloc(64, sizeof(int16_t) * sz * sz);
    if (!buf) {
        exit(1);
    }

    for (int i = 0; i < sz * sz; i++) {
        buf[i] = (int16_t)(i & 0xFF);
    }

    for (int i = 0; i < 1024; i++) {
        ind[i] = 0.0;
    }
}