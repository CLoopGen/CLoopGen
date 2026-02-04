#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *y;
extern float mem[2];
extern  float *x;
extern  float *b;
extern  float *a;
extern int N;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_mem0 = mem[0];
    float temp_mem1 = mem[1];
    for (int i = 0; i < N; i++) {
        float xi = x[i];
        float yi = xi + temp_mem0;
        float new_mem0 = temp_mem1 + (b[0] * xi - a[0] * yi);
        float new_mem1 = b[1] * xi - a[1] * yi;
        temp_mem0 = new_mem0;
        temp_mem1 = new_mem1;
        y[i] = yi;
    }
    mem[0] = temp_mem0;
    mem[1] = temp_mem1;
}
