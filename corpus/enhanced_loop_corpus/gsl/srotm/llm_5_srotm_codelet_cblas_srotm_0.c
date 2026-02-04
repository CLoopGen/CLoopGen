#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  int N;
extern float *X;
extern  int incX;
extern float *Y;
extern  int incY;
extern int n;
extern int i;
extern int j;
extern float h11;
extern float h21;
extern float h12;
extern float h22;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (n = 0; n < N; n++) {
        const float w = X[i];
        const float z = Y[j];
        float new_x, new_y;
        new_x = h11 * w + h12 * z;
        new_y = h21 * w + h22 * z;

        if (incX % 2 == 0) {
            X[i] = new_x;
        } else {
            X[i] = w;
        }

        if (incY % 2 == 0) {
            Y[j] = new_y;
        } else {
            Y[j] = z;
        }

        i += incX;
        j += incY;
    }
}
