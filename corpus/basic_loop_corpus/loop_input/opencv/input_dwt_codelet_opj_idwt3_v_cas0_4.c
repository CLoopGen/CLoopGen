#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef size_t OPJ_SIZE_T;

OPJ_INT32 *tmp = NULL;
OPJ_INT32 len;
OPJ_INT32 *tiledp_col = NULL;
OPJ_SIZE_T stride;
OPJ_INT32 i;

void init_vars() {
    len = 65536; // Adjust for ~0.01s runtime: approx 256MB of data (65536 * sizeof(int32_t) * 2)
    stride = 4;  // Stride greater than 1 to simulate strided access pattern

    tmp = (OPJ_INT32*)calloc(len, sizeof(OPJ_INT32));
    tiledp_col = (OPJ_INT32*)calloc(len * stride, sizeof(OPJ_INT32));

    if (!tmp || !tiledp_col) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (OPJ_INT32 j = 0; j < len; ++j) {
        tmp[j] = (OPJ_INT32)(j & 0xFFFF); // Initialize with some predictable pattern
    }
}