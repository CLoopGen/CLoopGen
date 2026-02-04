#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

ssize_t i;
unsigned char *p;
unsigned int T;
unsigned int W[64];

static unsigned char *data_buffer = NULL;

void init_vars() {
    const size_t buffer_size = 1 << 20; // 1MB
    data_buffer = (unsigned char *)calloc(buffer_size, sizeof(unsigned char));
    if (!data_buffer) {
        exit(1);
    }

    p = data_buffer;

    for (ssize_t j = 0; j < 16; j++) {
        unsigned int val = (unsigned int)(j * 0x0F0F0F0F);
        ((unsigned int *)p)[j] = ((val << 24) & 0xFF000000U) | ((val << 8) & 0x00FF0000U) |
                                 ((val >> 8) & 0x0000FF00U) | ((val >> 24) & 0x000000FFU);
    }

    T = 0;

    for (int k = 0; k < 64; k++) {
        W[k] = 0;
    }
}