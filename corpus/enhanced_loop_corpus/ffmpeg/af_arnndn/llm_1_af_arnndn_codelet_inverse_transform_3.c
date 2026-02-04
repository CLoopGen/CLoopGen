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
    for (int k = 0; k < ((120 << 2) + 1); k += 8) {
        for (int step = 0; step < 8; step++) {
            int i = k + step;
            if (i < ((120 << 2) + 1)) {
                x[i] = in[i];
            }
        }
    }
}
