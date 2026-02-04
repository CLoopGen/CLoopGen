#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *data;
extern int period;
extern int len;
extern  float g0;
extern  float g1;
extern  float g2;
extern float x4;
extern float x3;
extern float x2;
extern float x1;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with stride of 2
    // This variant processes every second element in a forward pass,
    // then handles the remaining elements in a second forward pass.
    // The striding changes memory access pattern to non-consecutive.

    for (int i = 0; i < len; i += 2) {
        float x0 = (i - period + 2 >= 0) ? data[i - period + 2] : 0.0f;
        data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
        x4 = x3;
        x3 = x2;
        x2 = x1;
        x1 = x0;
    }

    for (int i = 1; i < len; i += 2) {
        float x0 = (i - period + 2 >= 0) ? data[i - period + 2] : 0.0f;
        data[i] += g0 * x2 + g1 * (x1 + x3) + g2 * (x0 + x4);
        x4 = x3;
        x3 = x2;
        x2 = x1;
        x1 = x0;
    }
}
