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
        if (!(i & 1)) {
            x[i] = in[i];
        } else {
            x[i].re = 0.0f;
            x[i].im = 0.0f;
        }
    }
}
