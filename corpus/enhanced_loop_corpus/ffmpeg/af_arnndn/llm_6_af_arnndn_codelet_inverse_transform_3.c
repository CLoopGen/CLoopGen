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
    AVComplexFloat temp[961];
    for (int i = 0; i < ((120 << 2) + 1); i++) {
        temp[i] = in[i];
        x[i] = temp[i];
    }
}
