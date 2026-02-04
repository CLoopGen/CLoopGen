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
        INTFLOAT local_sum[2] = {0};
        for (n = 0; n < len; n++) {
            local_sum[0] += in[i][n][0];
            local_sum[1] += in[i][n][1];
            out[0][n][i] = local_sum[0];
            out[1][n][i] = local_sum[1];
        }
    }
}
