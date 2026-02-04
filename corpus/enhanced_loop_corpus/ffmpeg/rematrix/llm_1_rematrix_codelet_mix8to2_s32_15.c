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
if (len > 0) {
    int i = 0;
    for (; i < len - 3; i += 4) {
        for (int j = 0; j < 4; j++) {
            int idx = i + j;
            int64_t t = in[2][idx] * (int64_t)coeffp[0 * 8 + 2] + in[3][idx] * (int64_t)coeffp[0 * 8 + 3];
            out[0][idx] = (((t + in[0][idx] * (int64_t)coeffp[0 * 8 + 0] + in[4][idx] * (int64_t)coeffp[0 * 8 + 4] + in[6][idx] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
            out[1][idx] = (((t + in[1][idx] * (int64_t)coeffp[1 * 8 + 1] + in[5][idx] * (int64_t)coeffp[1 * 8 + 5] + in[7][idx] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
        }
    }
    for (; i < len; i++) {
        int64_t t = in[2][i] * (int64_t)coeffp[0 * 8 + 2] + in[3][i] * (int64_t)coeffp[0 * 8 + 3];
        out[0][i] = (((t + in[0][i] * (int64_t)coeffp[0 * 8 + 0] + in[4][i] * (int64_t)coeffp[0 * 8 + 4] + in[6][i] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][i] = (((t + in[1][i] * (int64_t)coeffp[1 * 8 + 1] + in[5][i] * (int64_t)coeffp[1 * 8 + 5] + in[7][i] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }
}
}
