#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float c[3][3];
extern  float a[3][3];
extern  float b[3][3];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            float sum = 0.F;
            for (int k = 0; k < 3; ++k) {
                if (a[i][k] != 0.F && b[k][j] != 0.F) {
                    sum += a[i][k] * b[k][j];
                }
            }
            c[i][j] = sum;
        }
    }
}
