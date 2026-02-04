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
    for (i = 0; i < size; i++) {
        if (in[i] > 0.0f) {
            cost += in[i] * in[i];
        } else {
            cost += 0.0f;
        }
    }
}
