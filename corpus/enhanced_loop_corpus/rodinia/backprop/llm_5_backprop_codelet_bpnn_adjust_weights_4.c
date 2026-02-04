#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *delta;
extern float *ly;
extern float **w;
extern float **oldw;
extern int ndelta;
extern int nly;
extern float new_dw;
extern int k;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (j = 1; j <= ndelta; j++) {
        for (k = 0; k <= nly; k++) {
            if (ly[k] != 0.0f || oldw[k][j] != 0.0f) {
                new_dw = ((0.29999999999999999 * delta[j] * ly[k]) + (0.29999999999999999 * oldw[k][j]));
                w[k][j] += new_dw;
                oldw[k][j] = new_dw;
            }
        }
    }
}
