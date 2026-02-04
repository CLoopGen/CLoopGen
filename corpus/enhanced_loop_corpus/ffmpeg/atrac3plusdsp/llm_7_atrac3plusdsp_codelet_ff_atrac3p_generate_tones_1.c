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
    for (i = 1; i < 128; i++) {
        out[i] += wavreg1[i-1] + wavreg2[i];
    }
    // Handle first iteration separately to maintain semantic validity
    if (128 > 0) {
        out[0] += wavreg1[0] + wavreg2[0];
    }
}
