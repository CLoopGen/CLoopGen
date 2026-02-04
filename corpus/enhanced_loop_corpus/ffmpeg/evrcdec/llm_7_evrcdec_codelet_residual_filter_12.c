#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern  float *input;
extern  float *coef;
extern float *memory;
extern int length;
extern float sum;
extern int i;
extern int j;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        sum = input[i];
        float local_mem[10];
        // Remove loop-carried dependency on memory by using local copy
        for (j = 0; j < 10; j++) {
            local_mem[j] = memory[j];
        }
        for (j = 9; j > 0; j--) {
            sum += coef[j] * local_mem[j];
            local_mem[j] = local_mem[j - 1]; // No interference with next iteration's memory
        }
        sum += coef[0] * local_mem[0];
        // Write back only the new value at start of memory after full computation
        memory[0] = input[i];
        output[i] = sum;
    }
}
