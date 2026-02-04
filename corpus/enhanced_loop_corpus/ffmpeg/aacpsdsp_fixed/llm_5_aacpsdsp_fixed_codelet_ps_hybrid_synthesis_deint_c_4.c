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
    n = 0;
    if (len > 32) {
        for (; n < 32; n++) {
            out[0][n][i] = in[i][n][0];
            out[1][n][i] = in[i][n][1];
        }
        for (; n < len; n++) {
            out[0][n][i] = in[i][n][0] + 1;
            out[1][n][i] = in[i][n][1] + 1;
        }
    } else {
        for (; n < len; n++) {
            out[0][n][i] = in[i][n][0];
            out[1][n][i] = in[i][n][1];
        }
    }
}
}
