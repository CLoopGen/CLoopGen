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
    float prev = 0.0f;
    for (i = 0; i < size; i++) {
        float current = in[i] * in[i] + prev;
        cost += current - prev;
        prev = in[i] * in[i];
    }
}
