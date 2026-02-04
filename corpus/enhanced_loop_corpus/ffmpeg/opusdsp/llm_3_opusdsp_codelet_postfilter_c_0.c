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
    // Variant 2: Reverse consecutive memory access
    // Instead of processing from start to end, this variant
    // accesses the array in reverse order, maintaining dependencies
    // by reversing the update sequence of shift register variables (x0-x4).
    // We reconstruct the state history assuming reverse traversal.

    float temp_x[5] = {0}; // Temporary buffer to simulate reverse-shifted state
    int offset = len - 1;

    // Initialize tail values for reverse propagation
    temp_x[0] = x4; // x4 at end becomes x0 in reverse step
    temp_x[1] = x3;
    temp_x[2] = x2;
    temp_x[3] = x1;
    temp_x[4] = 0;  // dummy placeholder

    for (int i = len - 1; i >= 0; i--) {
        float x0 = (i - period + 2 >= 0) ? data[i - period + 2] : 0.0f;
        // Use reversed shift: upcoming values come from previously stored future states
        data[i] += g0 * temp_x[2] + g1 * (temp_x[3] + temp_x[1]) + g2 * (x0 + temp_x[0]);

        // Shift backward: simulate reverse of original shift
        temp_x[4] = temp_x[3];
        temp_x[3] = temp_x[2];
        temp_x[2] = temp_x[1];
        temp_x[1] = temp_x[0];
        temp_x[0] = x0;
    }
}
