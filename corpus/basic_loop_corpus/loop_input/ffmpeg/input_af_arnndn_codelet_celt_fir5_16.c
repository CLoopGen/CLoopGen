#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>
#include <stddef.h>

float *x;
float *y;
int N;
float num0;
float num1;
float num2;
float num3;
float num4;
float mem0;
float mem1;
float mem2;
float mem3;
float mem4;

void init_vars() {
    N = 65536; 

    x = (float *)aligned_alloc(32, N * sizeof(float));
    y = (float *)aligned_alloc(32, N * sizeof(float));

    for (int i = 0; i < N; i++) {
        x[i] = 1.0f / (i + 1);
        y[i] = 0.0f;
    }

    num0 = 1.0f;
    num1 = 0.9f;
    num2 = 0.8f;
    num3 = 0.7f;
    num4 = 0.6f;

    mem0 = 0.0f;
    mem1 = 0.0f;
    mem2 = 0.0f;
    mem3 = 0.0f;
    mem4 = 0.0f;
}