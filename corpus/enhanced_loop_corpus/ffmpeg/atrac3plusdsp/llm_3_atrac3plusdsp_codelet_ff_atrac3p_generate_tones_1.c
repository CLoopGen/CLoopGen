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
    // Variant 2: Reverse consecutive memory access – traverse arrays from end to beginning
    for (i = 127; i >= 0; i--)
        out[i] += wavreg1[i] + wavreg2[i];
}
