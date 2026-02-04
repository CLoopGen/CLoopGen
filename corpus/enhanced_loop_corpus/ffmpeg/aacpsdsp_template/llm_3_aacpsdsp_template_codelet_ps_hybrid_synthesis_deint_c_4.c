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
for (; i < 64; i++) {
    for (n = 0; n < len; n++) {
        size_t idx = i * 32 * 2 + n * 2;
        out[0][n][i] = ((INTFLOAT*)in)[idx];
        out[1][n][i] = ((INTFLOAT*)in)[idx + 1];
    }
}
}
