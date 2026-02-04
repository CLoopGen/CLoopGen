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
for (i = 0; i < len; i += 2) {
    for (int j = 0; j < 2 && (i + j) < len; j++) {
        int64_t t = in[2][i + j] * (int64_t)coeffp[0 * 8 + 2] + in[3][i + j] * (int64_t)coeffp[0 * 8 + 3];
        out[0][i + j] = (((t + in[0][i + j] * (int64_t)coeffp[0 * 8 + 0] + in[4][i + j] * (int64_t)coeffp[0 * 8 + 4] + in[6][i + j] * (int64_t)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][i + j] = (((t + in[1][i + j] * (int64_t)coeffp[1 * 8 + 1] + in[5][i + j] * (int64_t)coeffp[1 * 8 + 5] + in[7][i + j] * (int64_t)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }
}
}
