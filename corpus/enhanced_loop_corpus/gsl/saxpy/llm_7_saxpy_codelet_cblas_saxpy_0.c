#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float alpha;
extern  float *X;
extern float *Y;
extern int i;
extern  int m;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_Y = Y[0];
    for (i = 1; i < m; i++) {
        float current_Y = Y[i];
        Y[i] = prev_Y + alpha * X[i];
        prev_Y = current_Y;
    }
    if (m > 0) {
        Y[0] += alpha * X[0];
    }
}
