#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern int16_t **out;
extern  int16_t **in;
extern int *coeffp;
extern integer len;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < len; i += 2) {
    if (i + 1 < len) {
        int t0 = in[2][i] * (int)coeffp[0 * 8 + 2] + in[3][i] * (int)coeffp[0 * 8 + 3];
        int t1 = in[2][i+1] * (int)coeffp[0 * 8 + 2] + in[3][i+1] * (int)coeffp[0 * 8 + 3];

        out[0][i] = (((t0 + in[0][i] * (int)coeffp[0 * 8 + 0] + in[4][i] * (int)coeffp[0 * 8 + 4] + in[6][i] * (int)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[0][i+1] = (((t1 + in[0][i+1] * (int)coeffp[0 * 8 + 0] + in[4][i+1] * (int)coeffp[0 * 8 + 4] + in[6][i+1] * (int)coeffp[0 * 8 + 6]) + 16384) >> 15);

        out[1][i] = (((t0 + in[1][i] * (int)coeffp[1 * 8 + 1] + in[5][i] * (int)coeffp[1 * 8 + 5] + in[7][i] * (int)coeffp[1 * 8 + 7]) + 16384) >> 15);
        out[1][i+1] = (((t1 + in[1][i+1] * (int)coeffp[1 * 8 + 1] + in[5][i+1] * (int)coeffp[1 * 8 + 5] + in[7][i+1] * (int)coeffp[1 * 8 + 7]) + 16384) >> 15);
    } else {
        int t = in[2][i] * (int)coeffp[0 * 8 + 2] + in[3][i] * (int)coeffp[0 * 8 + 3];
        out[0][i] = (((t + in[0][i] * (int)coeffp[0 * 8 + 0] + in[4][i] * (int)coeffp[0 * 8 + 4] + in[6][i] * (int)coeffp[0 * 8 + 6]) + 16384) >> 15);
        out[1][i] = (((t + in[1][i] * (int)coeffp[1 * 8 + 1] + in[5][i] * (int)coeffp[1 * 8 + 5] + in[7][i] * (int)coeffp[1 * 8 + 7]) + 16384) >> 15);
    }
}
}
