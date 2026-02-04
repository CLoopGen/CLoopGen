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
        int stride = (i < 32) ? 1 : 2;
        for (j = 0; j < len; j += stride) {
            out[i][j][0] = L[0][j][i];
            out[i][j][1] = L[1][j][i];
            if (stride == 2 && j + 1 < len) {
                out[i][j+1][0] = L[0][j+1][i];
                out[i][j+1][1] = L[1][j+1][i];
            }
        }
    }
}
