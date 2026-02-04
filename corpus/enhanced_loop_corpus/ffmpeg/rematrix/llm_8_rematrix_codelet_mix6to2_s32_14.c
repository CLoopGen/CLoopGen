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
    int64_t t0 = in[2][i] * (int64_t)coeffp[0 * 6 + 2] + in[3][i] * (int64_t)coeffp[0 * 6 + 3];
    int64_t t1 = (i+1 < len) ? (in[2][i+1] * (int64_t)coeffp[0 * 6 + 2] + in[3][i+1] * (int64_t)coeffp[0 * 6 + 3]) : 0;
    out[0][i] = (((t0 + in[0][i] * (int64_t)coeffp[0 * 6 + 0] + in[4][i] * (int64_t)coeffp[0 * 6 + 4]) + 16384) >> 15);
    out[1][i] = (((t0 + in[1][i] * (int64_t)coeffp[1 * 6 + 1] + in[5][i] * (int64_t)coeffp[1 * 6 + 5]) + 16384) >> 15);
    if (i+1 < len) {
        out[0][i+1] = (((t1 + in[0][i+1] * (int64_t)coeffp[0 * 6 + 0] + in[4][i+1] * (int64_t)coeffp[0 * 6 + 4]) + 16384) >> 15);
        out[1][i+1] = (((t1 + in[1][i+1] * (int64_t)coeffp[1 * 6 + 1] + in[5][i+1] * (int64_t)coeffp[1 * 6 + 5]) + 16384) >> 15);
    }
}
}
