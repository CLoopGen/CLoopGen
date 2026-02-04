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
    int64_t t = in[2][i] * (int64_t)coeffp[0 * 8 + 2] + in[3][i] * (int64_t)coeffp[0 * 8 + 3];

    int64_t sum0 = t + in[0][i] * (int64_t)coeffp[0 * 8 + 0] + in[4][i] * (int64_t)coeffp[0 * 8 + 4] + in[6][i] * (int64_t)coeffp[0 * 8 + 6];
    int64_t sum1 = t + in[1][i] * (int64_t)coeffp[1 * 8 + 1] + in[5][i] * (int64_t)coeffp[1 * 8 + 5] + in[7][i] * (int64_t)coeffp[1 * 8 + 7];

    // Additional computational load: simulate a lightweight filter feedback
    if (i > 0) {
        sum0 += (int64_t)(out[0][i-1]) * 2;
        sum1 += (int64_t)(out[1][i-1]) * 2;
    }

    out[0][i] = ((sum0 + 16384) >> 15);
    out[1][i] = ((sum1 + 16384) >> 15);
}
}
