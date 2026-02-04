#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern double out[3][3];
extern int i;
extern int j;
extern double det;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
int i, j;
for (i = 0; i < 2; i++) {
    for (j = 0; j < 3; j += 2) {
        if (i * j != 0)
            out[i][j] *= det * det;
        else
            out[i][j] += det;
    }
}
}
