#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *work;
extern float *data;
extern int i;
extern float gain;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp[40];
    for (i = 0; i < 40; i++)
        temp[i] = gain * work[i];
    for (i = 0; i < 40; i++)
        data[i] -= temp[i];
}
