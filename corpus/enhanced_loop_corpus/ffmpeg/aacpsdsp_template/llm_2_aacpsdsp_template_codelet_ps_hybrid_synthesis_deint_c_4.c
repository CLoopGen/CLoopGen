#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT (*in)[32][2];
extern int i;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < 64; i++) {
    INTFLOAT (*local_in)[32][2] = in;
    INTFLOAT (*out0)[64] = out[0];
    INTFLOAT (*out1)[64] = out[1];
    for (n = 0; n < len; n++) {
        out0[n][i] = local_in[i][n][0];
        out1[n][i] = local_in[i][n][1];
    }
}
}
