#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef float INTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT (*in)[32][2];
extern int i;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        for (int j = 0; j < 2; j++) {
            for (n = 0; n < len; n++) {
                out[j][n][i] = in[i][n][j];
            }
        }
    }
}
