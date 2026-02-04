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
    // Variant 2: Reduced computational complexity by decreasing effective trip count and simplifying dependencies.
    // The inner loop now runs only 5 iterations instead of 9, reducing arithmetic intensity.
    // Also, memory shift is simplified to a smaller window.
    for (i = 0; i < length; i++) {
        sum = input[i];
        for (j = 5 - 1; j > 0; j--) {
            sum += coef[j] * memory[j];
            memory[j] = memory[j - 1];
        }
        sum += coef[0] * memory[0];
        memory[0] = input[i];
        output[i] = sum;
    }
}
