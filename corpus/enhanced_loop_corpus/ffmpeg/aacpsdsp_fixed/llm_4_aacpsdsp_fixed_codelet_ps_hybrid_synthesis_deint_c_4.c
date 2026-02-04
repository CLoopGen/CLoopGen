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
for (; i < 64; i++) {
    if (i % 2 == 0) {
        for (n = 0; n < len; n++) {
            out[0][n][i] = in[i][n][0];
            out[1][n][i] = in[i][n][1];
        }
    } else {
        for (n = 0; n < len; n += 2) {
            if (n + 1 < len) {
                out[0][n][i] = in[i][n][0];
                out[1][n][i] = in[i][n][1];
                out[0][n+1][i] = in[i][n+1][0];
                out[1][n+1][i] = in[i][n+1][1];
            } else {
                out[0][n][i] = in[i][n][0];
                out[1][n][i] = in[i][n][1];
            }
        }
    }
}
}
