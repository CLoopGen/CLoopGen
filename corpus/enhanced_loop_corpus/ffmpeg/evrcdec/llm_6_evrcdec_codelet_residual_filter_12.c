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
    float temp_sum = 0.0f;
    for (i = 0; i < length; i++) {
        temp_sum = input[i];
        memory[0] = input[i]; // Update memory early to create WAW dependency across iterations
        for (j = 1; j < 10; j++) {
            temp_sum += coef[j] * memory[j];
            memory[j] = memory[j - 1]; // Shift after use — creates RAW dependency within inner loop
        }
        temp_sum += coef[0] * memory[0];
        output[i] = temp_sum;
    }
}
