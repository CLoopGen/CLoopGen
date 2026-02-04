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
    // Variant 1: Consecutive Memory Access Pattern
    // Reorganize data access to promote spatial locality by processing multiple elements at once
    // and accessing arrays in a more sequential manner. Assuming input/output are large enough.
    for (i = 0; i <= len - 4; i += 4) {
        int64_t t0 = in[2][i+0] * (int64_t)coeffp[0 * 8 + 2] + in[3][i+0] * (int64_t)coeffp[0 * 8 + 3];
        int64_t t1 = in[2][i+1] * (int64_t)coeffp[0 * 8 + 2] + in[3][i+1] * (int64_t)coeffp[0 * 8 + 3];
        int64_t t2 = in[2][i+2] * (int64_t)coeffp[0 * 8 + 2] + in[3][i+2] * (int64_t)coeffp[0 * 8 + 3];
        int64_t t3 = in[2][i+3] * (int64_t)coeffp[0 * 8 + 2] + in[3][i+3] * (int64_t)coeffp[0 * 8 + 3];

        out[0][i+0] = (((t0 + in[0][i+0] * (int64_t)coeffp[0 * 8 + 0] + in[4][i+0] * (int64_t)coeffp[0 * 8 + 4] + in[6][i+0] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[0][i+1] = (((t1 + in[0][i+1] * (int64_t)coeffp[0 * 8 + 0] + in[4][i+1] * (int64_t)coeffp[0 * 8 + 4] + in[6][i+1] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[0][i+2] = (((t2 + in[0][i+2] * (int64_t)coeffp[0 * 8 + 0] + in[4][i+2] * (int64_t)coeffp[0 * 8 + 4] + in[6][i+2] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[0][i+3] = (((t3 + in[0][i+3] * (int64_t)coeffp[0 * 8 + 0] + in[4][i+3] * (int64_t)coeffp[0 * 8 + 4] + in[6][i+3] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);

        out[1][i+0] = (((t0 + in[1][i+0] * (int64_t)coeffp[1 * 8 + 1] + in[5][i+0] * (int64_t)coeffp[1 * 8 + 5] + in[7][i+0] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
        out[1][i+1] = (((t1 + in[1][i+1] * (int64_t)coeffp[1 * 8 + 1] + in[5][i+1] * (int64_t)coeffp[1 * 8 + 5] + in[7][i+1] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
        out[1][i+2] = (((t2 + in[1][i+2] * (int64_t)coeffp[1 * 8 + 1] + in[5][i+2] * (int64_t)coeffp[1 * 8 + 5] + in[7][i+2] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
        out[1][i+3] = (((t3 + in[1][i+3] * (int64_t)coeffp[1 * 8 + 1] + in[5][i+3] * (int64_t)coeffp[1 * 8 + 5] + in[7][i+3] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }
    // Handle remaining elements if len is not a multiple of 4
    for (; i < len; i++) {
        int64_t t = in[2][i] * (int64_t)coeffp[0 * 8 + 2] + in[3][i] * (int64_t)coeffp[0 * 8 + 3];
        out[0][i] = (((t + in[0][i] * (int64_t)coeffp[0 * 8 + 0] + in[4][i] * (int64_t)coeffp[0 * 8 + 4] + in[6][i] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][i] = (((t + in[1][i] * (int64_t)coeffp[1 * 8 + 1] + in[5][i] * (int64_t)coeffp[1 * 8 + 5] + in[7][i] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }
}
