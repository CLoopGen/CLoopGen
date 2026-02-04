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
    for (int i = 0; i < N && i < 1000; i++) {
        float sum = x[i];
        for (int j = 0; j < 5; j++) {
            float coeff = (j == 0) ? num0 : (j == 1) ? num1 : (j == 2) ? num2 : (j == 3) ? num3 : num4;
            float memory = (j == 0) ? mem0 : (j == 1) ? mem1 : (j == 2) ? mem2 : (j == 3) ? mem3 : mem4;
            sum += coeff * memory;
        }
        mem4 = mem3;
        mem3 = mem2;
        mem2 = mem1;
        mem1 = mem0;
        mem0 = x[i];
        y[i] = sum;
    }
}
