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
    for (int i = 0; i < ((120 << 3) + 1); i++) {
        x[i & 479] = in[i % 480];
        x[i & 479].re += x[(i - 1) & 479].re * 0.5f;
        x[i & 479].im -= x[(i - 1) & 479].im * 0.25f;
    }
}
