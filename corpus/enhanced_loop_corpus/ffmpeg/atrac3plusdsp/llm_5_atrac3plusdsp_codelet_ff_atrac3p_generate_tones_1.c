#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *out;
extern __attribute__((aligned(32))) float wavreg1[128];
extern __attribute__((aligned(32))) float wavreg2[128];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 128; i++) {
        if (wavreg1[i] >= 0.0f) { // Only process if wavreg1[i] is non-negative
            out[i] += wavreg1[i] + wavreg2[i];
        }
    }
}
