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
    for (i = 0; i < 64; i += 2) {
        for (j = 0; j < len; j++) {
            out[i][j][0] = L[0][j][i];
            out[i][j][1] = L[1][j][i];
            if (i + 1 < 64) {
                out[i+1][j][0] = L[0][j][i+1];
                out[i+1][j][1] = L[1][j][i+1];
            }
        }
    }
}
