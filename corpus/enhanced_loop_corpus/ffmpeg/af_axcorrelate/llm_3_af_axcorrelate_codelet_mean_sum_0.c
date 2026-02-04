#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern float mean_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int stride = 4;
    for (int i = 0; i < size; i += stride) {
        for (int j = 0; j < stride && (i + j) < size; j++) {
            mean_sum += in[i + j];
        }
    }
}
