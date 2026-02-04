#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *in;
extern int size;
extern int i;
extern float cost;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp_cost = 0.0f;
    for (i = 0; i < size; i++) {
        temp_cost += in[i] * in[i];
    }
    cost = temp_cost;
}
