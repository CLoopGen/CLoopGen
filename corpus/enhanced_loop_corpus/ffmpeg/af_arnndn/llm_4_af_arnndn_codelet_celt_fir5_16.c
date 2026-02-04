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
for (int i = 0; i < N; i++) {
    float sum = x[i];
    if (i >= 5) {
        sum += (num0 * mem0);
        sum += (num1 * mem1);
        sum += (num2 * mem2);
        sum += (num3 * mem3);
        sum += (num4 * mem4);
    }
    mem4 = mem3;
    mem3 = mem2;
    mem2 = mem1;
    mem1 = mem0;
    mem0 = x[i];
    y[i] = sum;
}
}
