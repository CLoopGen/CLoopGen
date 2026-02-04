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
        int offset = (i & 1) ? 1 : 0;
        for (j = offset; j < len; j++) {
            if (j >= len) continue;
            out[i][j][0] = L[0][j][i];
            out[i][j][1] = L[1][j][i];
        }
        if (i % 4 == 0 && len > 0) {
            out[i][0][0] = L[0][0][i] + 1.0f;
            out[i][0][1] = L[1][0][i] + 1.0f;
        }
    }
}
