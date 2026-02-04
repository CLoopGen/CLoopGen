#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT in[5][44][2];
extern INTFLOAT L[2][38][64];
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (i = 0; i < 5; i++) {
    for (j = 0; j < 38; j++) {
        in[i][j + 6][0] = L[0][j][i] + L[0][j][(i + 1) % 5];
        in[i][j + 6][1] = L[1][j][i] - L[1][j][(i + 1) % 5];
        in[i][j + 6][0] *= 2;
        in[i][j + 6][1] *= 2;
    }
}
}
