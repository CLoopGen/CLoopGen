#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *x;
extern float *y;
extern int N;
extern float num0;
extern float num1;
extern float num2;
extern float num3;
extern float num4;
extern float mem0;
extern float mem1;
extern float mem2;
extern float mem3;
extern float mem4;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < N; i += 2) {
        float sum1 = x[i];
        float sum2 = (i + 1 < N) ? x[i + 1] : 0.0f;
        sum1 += (num0 * mem0) + (num1 * mem1);
        sum2 += (num0 * mem1) + (num1 * mem2);
        sum1 += (num2 * mem2) + (num3 * mem3);
        sum2 += (num2 * mem3) + (num3 * mem4);
        sum1 += num4 * mem4;
        sum2 += num4 * mem0;

        mem4 = mem3;
        mem3 = mem2;
        mem2 = mem1;
        mem1 = mem0;
        mem0 = x[i];

        y[i] = sum1;
        if (i + 1 < N) {
            mem4 = mem3;
            mem3 = mem2;
            mem2 = mem1;
            mem1 = mem0;
            mem0 = x[i + 1];
            y[i + 1] = sum2;
        }
    }
}
