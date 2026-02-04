#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef struct _BC7Colors {
    unsigned char r[6];
    unsigned char g[6];
    unsigned char b[6];
    unsigned char a[6];
} BC7Colors;

BC7Colors *endpoints;
unsigned char alpha_bits;
unsigned char color_bits;
size_t num_subsets;
size_t i;

void init_vars() {
    color_bits = 5;
    alpha_bits = 8;
    num_subsets = 3;

    endpoints = aligned_alloc(16, sizeof(BC7Colors));
    if (!endpoints) exit(1);

    for (int idx = 0; idx < 6; ++idx) {
        endpoints->r[idx] = (unsigned char)((idx * 31) % 256);
        endpoints->g[idx] = (unsigned char)((idx * 27) % 256);
        endpoints->b[idx] = (unsigned char)((idx * 23) % 256);
        endpoints->a[idx] = (unsigned char)((idx * 19) % 256);
    }
}