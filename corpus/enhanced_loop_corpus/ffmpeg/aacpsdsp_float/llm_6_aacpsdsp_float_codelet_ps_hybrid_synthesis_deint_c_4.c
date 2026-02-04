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
        INTFLOAT temp1[38], temp2[38];
        for (n = 0; n < len; n++) {
            temp1[n] = in[i][n][0];
            temp2[n] = in[i][n][1];
        }
        for (n = 0; n < len; n++) {
            out[0][n][i] = temp1[n];
            out[1][n][i] = temp2[n];
        }
    }
}
