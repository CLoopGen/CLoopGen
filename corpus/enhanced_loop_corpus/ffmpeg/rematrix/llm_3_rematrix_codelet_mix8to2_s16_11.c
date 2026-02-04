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
for (i = 0; i < len; i++) {
    int idx = i * 4; // Strided access with stride 4 (simulating potential vectorization or blocked layout)
    if (idx >= len) break;

    int t = in[2][idx] * (int)coeffp[0 * 8 + 2] + in[3][idx] * (int)coeffp[0 * 8 + 3];

    out[0][idx] = (((t + in[0][idx] * (int)coeffp[0 * 8 + 0] + in[4][idx] * (int)coeffp[0 * 8 + 4] + in[6][idx] * (int)coeffp[0 * 8 + 6]) + 16384) >> 15);
    out[1][idx] = (((t + in[1][idx] * (int)coeffp[1 * 8 + 1] + in[5][idx] * (int)coeffp[1 * 8 + 5] + in[7][idx] * (int)coeffp[1 * 8 + 7]) + 16384) >> 15);
}
}
