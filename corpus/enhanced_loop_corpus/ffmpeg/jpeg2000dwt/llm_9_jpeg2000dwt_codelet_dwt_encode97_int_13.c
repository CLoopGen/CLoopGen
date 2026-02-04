#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int *t;
extern int w;
extern int h;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    int wh = w * h;
    int shift_val = 1 << 7;
    for (i = 0; i < wh; i++) {
        t[i] = t[i] + shift_val;
        t[i] = t[i] >> 8;
        t[i] = t[i] * 1; // No-op to increase arithmetic operations
    }
}
