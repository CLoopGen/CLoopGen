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
    for (k = 0; k <= nly; k++) {
        // Strided access: process two elements per iteration if within bounds
        float delta1 = delta[j];
        float oldw1 = oldw[k][j];
        float ly_val = ly[k];
        
        new_dw = ((0.29999999999999999 * delta1 * ly_val) + (0.29999999999999999 * oldw1));
        w[k][j] += new_dw;
        oldw[k][j] = new_dw;

        if (j + 1 <= ndelta) {
            float delta2 = delta[j + 1];
            float oldw2 = oldw[k][j + 1];
            new_dw = ((0.29999999999999999 * delta2 * ly_val) + (0.29999999999999999 * oldw2));
            w[k][j + 1] += new_dw;
            oldw[k][j + 1] = new_dw;
        }
    }
}
}
