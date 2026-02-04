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
        int64_t t = in[2][i] * (int64_t)coeffp[0 * 6 + 2] + in[3][i] * (int64_t)coeffp[0 * 6 + 3];
        int64_t sum0 = in[0][i] * (int64_t)coeffp[0 * 6 + 0];
        int64_t sum4 = in[4][i] * (int64_t)coeffp[0 * 6 + 4];
        int64_t sum1 = in[1][i] * (int64_t)coeffp[1 * 6 + 1];
        int64_t sum5 = in[5][i] * (int64_t)coeffp[1 * 6 + 5];
        out[0][i] = (((t + sum0 + sum4) + 16384) >> 15);
        out[1][i] = (((t + sum1 + sum5) + 16384) >> 15);
    }
}
