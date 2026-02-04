#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT (*in)[32][2];
extern int i;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 64; i++) {
        INTFLOAT local_out0[38], local_out1[38];
        for (n = 0; n < len; n++) {
            local_out0[n] = in[i][n][0];
            local_out1[n] = in[i][n][1];
        }
        for (n = 0; n < len; n++) {
            out[0][n][i] = local_out0[n];
            out[1][n][i] = local_out1[n];
        }
    }
}
