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
for (j = 1; j <= ndelta; j += 2) {
    if (j + 1 <= ndelta) {
        for (k = 0; k <= nly; k++) {
            new_dw = (0.29999999999999999 * delta[j] * ly[k]) + (0.29999999999999999 * oldw[k][j]);
            w[k][j] += new_dw;
            oldw[k][j] = new_dw;

            new_dw = (0.29999999999999999 * delta[j+1] * ly[k]) + (0.29999999999999999 * oldw[k][j+1]);
            w[k][j+1] += new_dw;
            oldw[k][j+1] = new_dw;
        }
    } else {
        for (k = 0; k <= nly; k++) {
            new_dw = (0.29999999999999999 * delta[j] * ly[k]) + (0.29999999999999999 * oldw[k][j]);
            w[k][j] += new_dw;
            oldw[k][j] = new_dw;
        }
    }
}
}
