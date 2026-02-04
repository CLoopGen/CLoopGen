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
    for (int k = 0; k < len; k++) {
        for (i = 0; i < 64; i++) {
            out[i][k][0] = L[0][k][i];
            out[i][k][1] = L[1][k][i];
        }
    }
}
