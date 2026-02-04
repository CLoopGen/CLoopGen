#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int INTFLOAT;

extern INTFLOAT out[2][38][64];
extern INTFLOAT (*in)[32][2];
extern int i;
extern int len;
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 64; i++) {
        for (n = 0; n < len; n++) {
            for (int k = 0; k < 2; k++) {
                out[k][n][i] = in[i][n][k];
            }
        }
    }
}
