#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern  AVComplexFloat *in;
extern AVComplexFloat x[960];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (int i = 0; i < ((120 << 2) + 1); i++) {
        x[i] = in[i];
        x[i].re += x[i].im * 0.1f; 
    }
}
