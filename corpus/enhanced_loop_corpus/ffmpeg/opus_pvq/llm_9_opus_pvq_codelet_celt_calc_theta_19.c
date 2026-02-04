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
    int stride = 4;
    for (i = 0; i < N; i++) {
        float sum_x = 0.0f, sum_y = 0.0f;
        int end = (i + stride < N) ? i + stride : N;
        for (int j = i; j < end; j++) {
            sum_x += X[j] * X[j];
            sum_y += Y[j] * Y[j];
        }
        e[0] += sum_x;
        e[1] += sum_y;
        i = end - 1;
    }
}
