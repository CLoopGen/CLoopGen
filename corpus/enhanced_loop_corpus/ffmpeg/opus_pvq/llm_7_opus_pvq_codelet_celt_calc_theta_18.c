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
    float local_e0 = 0.0f;
    float local_e1 = 0.0f;
    for (i = 0; i < N; i++) {
        float xi = X[i];
        float yi = Y[i];
        local_e0 += (xi + yi) * (xi + yi);
        local_e1 += (xi - yi) * (xi - yi);
    }
    e[0] += local_e0;
    e[1] += local_e1;
}
