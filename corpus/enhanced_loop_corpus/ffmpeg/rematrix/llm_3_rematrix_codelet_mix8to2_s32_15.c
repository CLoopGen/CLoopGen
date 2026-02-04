#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int32_t **out;
extern  int32_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Strided Memory Access Pattern
    // Access memory with a fixed stride (e.g., every 2nd element) to simulate non-unit stride access
    // This could model scenarios where only certain samples are processed or cache behavior is altered
    const int stride = 2;
    int n = (len + stride - 1) / stride;  // Number of iterations for strided access

    for (i = 0; i < n; i++) {
        int idx = i * stride;  // Compute actual index with stride
        if (idx >= len) break;

        int64_t t = in[2][idx] * (int64_t)coeffp[0 * 8 + 2] + in[3][idx] * (int64_t)coeffp[0 * 8 + 3];

        out[0][idx] = (((t + in[0][idx] * (int64_t)coeffp[0 * 8 + 0] + in[4][idx] * (int64_t)coeffp[0 * 8 + 4] + in[6][idx] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][idx] = (((t + in[1][idx] * (int64_t)coeffp[1 * 8 + 1] + in[5][idx] * (int64_t)coeffp[1 * 8 + 5] + in[7][idx] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }

    // Process unaligned tail if stride does not cover all elements
    for (i = (n * stride); i < len; i++) {
        int64_t t = in[2][i] * (int64_t)coeffp[0 * 8 + 2] + in[3][i] * (int64_t)coeffp[0 * 8 + 3];
        out[0][i] = (((t + in[0][i] * (int64_t)coeffp[0 * 8 + 0] + in[4][i] * (int64_t)coeffp[0 * 8 + 4] + in[6][i] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][i] = (((t + in[1][i] * (int64_t)coeffp[1 * 8 + 1] + in[5][i] * (int64_t)coeffp[1 * 8 + 5] + in[7][i] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }
}
