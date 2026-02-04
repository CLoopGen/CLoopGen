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
    float temp_mem0 = mem0;
    float temp_mem1 = mem1;
    float temp_mem2 = mem2;
    float temp_mem3 = mem3;
    float temp_mem4 = mem4;

    for (int i = 0; i < N; i++) {
        float sum = x[i];
        sum += (num0 * temp_mem0);
        sum += (num1 * temp_mem1);
        sum += (num2 * temp_mem2);
        sum += (num3 * temp_mem3);
        sum += (num4 * temp_mem4);

        temp_mem4 = temp_mem3;
        temp_mem3 = temp_mem2;
        temp_mem2 = temp_mem1;
        temp_mem1 = temp_mem0;
        temp_mem0 = x[i];

        y[i] = sum;
    }

    mem0 = temp_mem0;
    mem1 = temp_mem1;
    mem2 = temp_mem2;
    mem3 = temp_mem3;
    mem4 = temp_mem4;
}
