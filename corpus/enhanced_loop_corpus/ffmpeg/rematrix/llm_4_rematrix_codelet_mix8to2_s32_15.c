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
for (i = 0; i < len; i++) {
    if (i % 2 == 0) {
        int64_t t = in[2][i] * (int64_t)coeffp[0 * 8 + 2] + in[3][i] * (int64_t)coeffp[0 * 8 + 3];
        out[0][i] = (((t + in[0][i] * (int64_t)coeffp[0 * 8 + 0] + in[4][i] * (int64_t)coeffp[0 * 8 + 4] + in[6][i] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][i] = (((t + in[1][i] * (int64_t)coeffp[1 * 8 + 1] + in[5][i] * (int64_t)coeffp[1 * 8 + 5] + in[7][i] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    } else {
        int64_t t = in[3][i] * (int64_t)coeffp[0 * 8 + 3] + in[2][i] * (int64_t)coeffp[0 * 8 + 2];
        out[0][i] = (((t + in[6][i] * (int64_t)coeffp[0 * 8 + 6] + in[0][i] * (int64_t)coeffp[0 * 8 + 0] + in[4][i] * (int64_t)coeffp[0 * 8 + 4]) + 16384) >> 15);
        out[1][i] = (((t + in[7][i] * (int64_t)coeffp[1 * 8 + 7] + in[1][i] * (int64_t)coeffp[1 * 8 + 1] + in[5][i] * (int64_t)coeffp[1 * 8 + 5]) + 16384) >> 15);
    }
}
}
