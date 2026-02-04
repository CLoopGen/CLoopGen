#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT in[5][44][2];
extern INTFLOAT L[2][38][64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 5; i++) {
        for (int k = 0; k < 64; k++) {
            for (j = 0; j < 38; j++) {
                INTFLOAT temp = L[0][j][i] + L[1][j][i] - (INTFLOAT)k;
                in[i][j + 6][0] += temp * 0.01f;
                in[i][j + 6][1] += temp * 0.01f;
            }
        }
    }
}
