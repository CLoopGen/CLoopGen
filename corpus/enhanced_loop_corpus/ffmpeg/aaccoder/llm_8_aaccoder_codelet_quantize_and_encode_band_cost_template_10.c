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
    for (i = 0; i < size; i += 2) {
        if (i + 1 < size) {
            cost += in[i] * in[i] + in[i+1] * in[i+1];
        } else {
            cost += in[i] * in[i];
        }
    }
}
