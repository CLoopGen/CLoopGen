#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float c[3][3];
extern  float a[3][3];
extern  float b[3][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
        float sum1 = 0.F, sum2 = 0.F;
        for (int k = 0; k < 3; k += 2) {
            sum1 += a[i][k] * b[k][j];
            if (k + 1 < 3)
                sum2 += a[i][k+1] * b[k+1][j];
        }
        c[i][j] = sum1 + sum2;
    }
}
}
