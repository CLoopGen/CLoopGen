#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
typedef struct AVComplexFloat {
    float re;
    float im;
} AVComplexFloat;

extern float *out;
extern AVComplexFloat y[960];

// Variable name mappings to avoid conflicts with system symbols

void loop(){
for (int i = 0; i < (2 * (120 << 2)); i++)
    out[i] = y[i].re / (2 * (120 << 2));

}
