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
        j = 9;
        for (; j > 0; j--) {
            if (coef[j] != 0.0f) {
                sum += coef[j] * memory[j];
            }
            memory[j] = memory[j - 1];
        }
        if (coef[0] != 0.0f) {
            sum += coef[0] * memory[0];
        }
        memory[0] = input[i];
        output[i] = sum;
    }
}
