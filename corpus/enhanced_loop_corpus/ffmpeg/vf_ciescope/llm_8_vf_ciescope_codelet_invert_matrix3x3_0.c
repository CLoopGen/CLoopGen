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
int i, j, k;
for (i = 0; i < 3; i++) {
    for (j = 0; j < 3; j++) {
        for (k = 0; k < 4; k++) {
            out[i][j] += det * (i + j);
        }
    }
}
}
