#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT (*out)[32][2];
extern INTFLOAT L[2][38][64];
extern int i;
extern int len;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (; i < 64; i++) {
        INTFLOAT temp0, temp1;
        for (j = 0; j < len; j++) {
            temp0 = L[0][j][i];
            temp1 = L[1][j][i];
            out[i][j][0] = temp0;
            out[i][j][1] = temp1;
        }
    }
}
