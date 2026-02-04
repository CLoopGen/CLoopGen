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
    int n = 2 * (120 << 2);
    for (int i = 0; i < n; i += 4) {
        out[i + 0] = y[i + 0].re / n;
        if (i + 1 < n) out[i + 1] = y[i + 1].re / n;
        if (i + 2 < n) out[i + 2] = y[i + 2].re / n;
        if (i + 3 < n) out[i + 3] = y[i + 3].re / n;
    }
}
