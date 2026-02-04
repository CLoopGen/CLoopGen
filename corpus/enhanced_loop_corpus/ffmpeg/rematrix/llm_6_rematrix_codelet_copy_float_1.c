#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef int integer;

extern float *out;
extern  float *in;
extern integer len;
extern int i;
extern float coeff;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float temp = 0.0f;
    for (i = 0; i < len; i++) {
        temp = coeff * in[i];
        out[i] = temp;
    }
}
