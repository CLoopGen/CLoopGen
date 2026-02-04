#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT (*out)[32][2];
extern INTFLOAT L[2][38][64];
extern int i;
extern int len;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (; i < 32; i++) {
    for (j = 0; j < len; j++) {
        INTFLOAT val0 = L[0][j][i] * L[0][j][i] + 0.5f;
        INTFLOAT val1 = L[1][j][i] * L[1][j][i] + 0.5f;
        out[i][j][0] = val0;
        out[i][j][1] = val1;
        out[i+32][j][0] = val1;
        out[i+32][j][1] = val0;
    }
}
}
