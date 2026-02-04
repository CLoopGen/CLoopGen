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
    for (; i < 64; i++) {
        for (j = 0; j < len; j++) {
            out[i][j][0] = L[0][len - 1 - j][i];
            out[i][j][1] = L[1][len - 1 - j][i];
        }
    }
}
