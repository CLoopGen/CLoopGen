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
    for (j = 9; j >= 0; j--) {
        if (j != 0) {
            sum += coef[j] * memory[j];
            memory[j] = memory[j - 1];
        } else {
            sum += coef[0] * memory[0];
            memory[0] = input[i];
        }
    }
    output[i] = sum;
}
}
