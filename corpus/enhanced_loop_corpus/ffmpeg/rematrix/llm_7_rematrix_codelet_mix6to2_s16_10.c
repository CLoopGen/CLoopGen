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
    int prev_out0 = 0;
    for (i = 0; i < len; i++) {
        int t = in[2][i] * (int)coeffp[0 * 6 + 2] + in[3][i] * (int)coeffp[0 * 6 + 3];
        int temp0 = t + in[0][i] * (int)coeffp[0 * 6 + 0] + in[4][i] * (int)coeffp[0 * 6 + 4];
        int temp1 = t + in[1][i] * (int)coeffp[1 * 6 + 1] + in[5][i] * (int)coeffp[1 * 6 + 5];

        // Introduce loop-carried dependence: out[0][i] depends on previous out[0][i-1]
        int adjusted_temp0 = (i == 0) ? temp0 : temp0 + prev_out0;
        out[0][i] = ((adjusted_temp0 + 16384) >> 15);
        out[1][i] = ((temp1 + 16384) >> 15);

        prev_out0 = out[0][i]; // Carry value forward (WAW and RAW dependency across iterations)
    }
}
