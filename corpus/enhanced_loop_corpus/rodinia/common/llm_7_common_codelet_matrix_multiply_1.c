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
    for (k = 0; k < size; k++)
        for (i = 0; i < size; i++) {
            float r = inputa[i * size + k];
            for (j = 0; j < size; j++)
                output[i * size + j] += r * inputb[k * size + j];
        }
}
