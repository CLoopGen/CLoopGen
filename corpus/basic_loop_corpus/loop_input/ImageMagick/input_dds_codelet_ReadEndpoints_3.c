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
size_t num_subsets;
size_t i;

void init_vars() {
    num_subsets = 3; // Ensures i goes up to num_subsets*2 = 6, which is within the [0,5] array bounds
    endpoints = (BC7Colors*)calloc(1, sizeof(BC7Colors));
    if (!endpoints) {
        exit(1);
    }
    for (int j = 0; j < 6; j++) {
        endpoints->r[j] = (unsigned char)(j + 1);
        endpoints->g[j] = (unsigned char)(j + 2);
        endpoints->b[j] = (unsigned char)(j + 3);
        endpoints->a[j] = (unsigned char)(j + 4);
    }
}