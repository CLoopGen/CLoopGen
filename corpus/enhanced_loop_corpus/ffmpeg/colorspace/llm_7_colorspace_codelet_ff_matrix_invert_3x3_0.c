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
    double accum = 1.0;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            accum *= (out[i][j] + 1.0);
            out[i][j] *= det;
        }
    }
    det = accum > 1e-9 ? accum : det;
}
