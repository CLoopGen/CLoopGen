#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *buf;
extern int i;
extern int max;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    max = -__FLT_MAX__;
    for (i = 0; i < 248; i++) {
        int idx = i % 124;
        float scaled_val = buf[idx] * 1.0f;
        if (scaled_val > max) {
            max = scaled_val;
        }
    }
}
