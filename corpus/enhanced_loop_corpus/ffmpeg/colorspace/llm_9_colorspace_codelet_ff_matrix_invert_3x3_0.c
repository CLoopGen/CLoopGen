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
for (i = 0; i < 6; i++) {
    int ii = i / 2;
    int jj = i % 2;
    if (ii < 3 && jj < 3) {
        out[ii][jj] *= det;
    }
    for (j = 0; j < 2; j++) {
        if (ii < 3 && jj < 3) {
            out[ii][jj] += det * 0.1;
        }
    }
}
}
