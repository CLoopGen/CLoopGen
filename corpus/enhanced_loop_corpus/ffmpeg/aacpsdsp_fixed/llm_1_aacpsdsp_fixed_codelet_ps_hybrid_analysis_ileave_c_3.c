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
    for (i = 0; i < 64; i++) {
        for (j = 0; j < len; j++) {
            for (int c = 0; c < 2; c++) {
                out[i][j][c] = L[c][j][i];
            }
        }
    }
}
