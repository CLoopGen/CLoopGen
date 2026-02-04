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
    len = 65536; // Adjust based on performance: ~0.01 sec on modern CPU
    stride = 4; // Reasonable stride value to prevent overlap and ensure spacing

    tmp = (OPJ_INT32*)calloc(len, sizeof(OPJ_INT32));
    tiledp_col = (OPJ_INT32*)calloc(len * stride, sizeof(OPJ_INT32));

    if (!tmp || !tiledp_col) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    for (OPJ_INT32 idx = 0; idx < len; ++idx) {
        tmp[idx] = (OPJ_INT32)(idx & 0xFFFF); // Initialize with sample data
    }

    i = 0;
}