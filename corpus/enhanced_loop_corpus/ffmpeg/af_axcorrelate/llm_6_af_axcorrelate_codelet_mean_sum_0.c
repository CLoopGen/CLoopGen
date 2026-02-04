#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern float mean_sum;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_sum = 0.0f;
    for (int i = 0; i < size; i++)
        temp_sum += in[i];
    mean_sum += temp_sum;
}
