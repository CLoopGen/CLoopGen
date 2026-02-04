#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *output;
extern float a;
extern float b;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev_output = 0.0f;
    for (i = 0; i < 1792; i++) {
        float current = output[i];
        output[i] *= a * (1791 - i) + b * i;
        // Introduce WAW and WAR: use of output[i] before and after write, plus loop-carried dependency via prev_output
        if (i > 0) {
            output[i] += prev_output * 0.1f; // Feedback introduces loop-carried dependence (WAW & RAW)
        }
        prev_output = current;
    }
}
