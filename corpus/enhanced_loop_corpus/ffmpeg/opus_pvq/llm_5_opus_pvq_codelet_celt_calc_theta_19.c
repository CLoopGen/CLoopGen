#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *X;
extern  float *Y;
extern int N;
extern int i;
extern float e[2];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < N; i++) {
        float x_val = X[i];
        float y_val = Y[i];
        int update_e0 = (i % 2) == 0;
        int update_e1 = (i % 2) == 1;

        if (update_e0) {
            e[0] += x_val * x_val;
        }
        if (update_e1) {
            e[1] += y_val * y_val;
        }
    }
}
