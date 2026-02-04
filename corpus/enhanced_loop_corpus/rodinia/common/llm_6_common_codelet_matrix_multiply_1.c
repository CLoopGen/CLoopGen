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
    float temp;
    for (i = 0; i < size; i++)
        for (j = 0; j < size; j++) {
            temp = 0.0f;
            for (k = 0; k < size; k++)
                temp += inputa[i * size + k] * inputb[k * size + j];
            output[i * size + j] = temp;
        }
}
