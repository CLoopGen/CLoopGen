#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *inputa;
extern float *inputb;
extern float *output;
extern int size;
extern int i;
extern int j;
extern int k;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int step = 2;
    for (i = 0; i < size; i++)
        for (k = 0; k < size; k += 2)
            for (j = 0; j < size; j++) {
                float temp1 = inputa[i * size + k] * inputb[k * size + j];
                float temp2 = (k + 1 < size) ? inputa[i * size + k + 1] * inputb[(k + 1) * size + j] : 0.0f;
                output[i * size + j] += temp1 + temp2;
            }
}
