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
    num_subsets = 128 * 1024; // Ensures endpoints->a has enough space: num_subsets * 2 <= 6
    while (num_subsets * 2 > 6) {
        num_subsets = num_subsets / 2;
    }

    endpoints = (BC7Colors*)calloc(1, sizeof(BC7Colors));
    if (!endpoints) {
        exit(1);
    }
}