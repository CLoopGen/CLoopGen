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
    // Variant 2: Indirect (gather) access using an index map
    // Simulates non-unit striding or arbitrary access via an index array
    // Here we assume indirect access through reversed order to simulate irregular pattern
    
    int *indices = (int*)malloc(N * sizeof(int));
    if (!indices) return; // Handle allocation failure
    
    for (int i = 0; i < N; i++) {
        indices[i] = N - 1 - i; // Reverse mapping: process from end to start
    }

    float temp_mem0 = mem0, temp_mem1 = mem1, temp_mem2 = mem2, temp_mem3 = mem3, temp_mem4 = mem4;

    for (int j = 0; j < N; j++) {
        int i = indices[j]; // Indirect access index
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

    // Update global state to reflect final filter state
    mem0 = temp_mem0; mem1 = temp_mem1; mem2 = temp_mem2; mem3 = temp_mem3; mem4 = temp_mem4;

    free(indices);
}
