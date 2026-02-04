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
    // Variant 2: Reverse order (consecutive but backward) memory access
    int n = (120 << 2) + 1;
    for (int i = n - 1; i >= 0; i--) {
        x[i] = in[i];
    }
}
