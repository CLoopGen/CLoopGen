#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float analysis_low[9];
extern float *input;
extern float *output;
extern  int low_size;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 10; i < 10 + low_size; i++) {
        float sum = 0.0f;
        for (int j = 0; j < 9; j++) {
            int index;
            if (j <= 4) {
                index = 2 * i - 14 + j;
            } else {
                index = 2 * i - 14 + (8 - j);
            }
            sum += input[index] * analysis_low[j <= 4 ? j : 8 - j];
        }
        output[i] = sum;
    }
}
