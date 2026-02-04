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
for (; i < 32; i++) {
    for (int j = 0; j < len; j++) {
        INTFLOAT temp1 = in[i][j][0];
        INTFLOAT temp2 = in[i][j][1];
        out[0][j][i] = temp1;
        out[1][j][i] = temp2;
        out[0][j][i+32] = in[i+32][j][0];
        out[1][j][i+32] = in[i+32][j][1];
    }
}
}
