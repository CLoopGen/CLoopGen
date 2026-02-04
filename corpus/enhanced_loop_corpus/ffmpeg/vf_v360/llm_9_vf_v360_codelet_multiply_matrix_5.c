#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float c[3][3];
extern  float a[3][3];
extern  float b[3][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
        float sum = 0.F;
        for (int k = 0; k < 2; k++)
            sum += a[i][k] * b[k][j];
        c[i][j] = sum;
    }
}
// Handle remaining elements with reduced computation
c[2][2] = a[2][0]*b[0][2] + a[2][1]*b[1][2] + a[2][2]*b[2][2];
}
