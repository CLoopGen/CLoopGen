#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

typedef int32_t OPJ_INT32;
typedef size_t OPJ_SIZE_T;

OPJ_INT32 *tiledp_col;
OPJ_SIZE_T stride;
OPJ_INT32 nb_cols;
OPJ_INT32 sn;
OPJ_INT32 len;
OPJ_INT32 c;
OPJ_INT32 *out;

void init_vars() {
    // Set parameters to control data size and loop iterations
    nb_cols = 8000;           // Number of columns to iterate over
    stride = 2000;            // Stride for accessing even/odd rows
    sn = 1;                   // Offset index for in_even pointer
    len = 2;                  // Inner loop length (must be <= available out elements)

    // Total memory needed: tiledp_col must support indexing up to (sn * stride + len * stride)
    // We need at least (stride * (sn + len)) elements safely accessible from base tiledp_col
    OPJ_SIZE_T total_tiledp_size = (OPJ_SIZE_T)(sn + len + nb_cols) * stride + 10;
    tiledp_col = (OPJ_INT32*)calloc(total_tiledp_size, sizeof(OPJ_INT32));
    if (!tiledp_col) exit(1);

    // Allocate and initialize output array
    out = (OPJ_INT32*)calloc(len + 10, sizeof(OPJ_INT32)); // Extra space to prevent overflow
    if (!out) exit(1);

    // Initialize out with safe values
    for (c = 0; c < len + 10; ++c) {
        out[c] = c * 31;
    }

    // Initialize tiledp_col data to ensure no undefined behavior in computation
    for (OPJ_SIZE_T i = 0; i < total_tiledp_size; ++i) {
        tiledp_col[i] = i % 256;
    }

    // Reset c for correct loop start
    c = 0;
}