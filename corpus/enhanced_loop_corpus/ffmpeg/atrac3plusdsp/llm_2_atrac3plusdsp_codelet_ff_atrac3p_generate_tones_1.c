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
    // Variant 1: Strided memory access with stride of 2, processing even indices first then odd
    for (i = 0; i < 128; i += 2)
        out[i] += wavreg1[i] + wavreg2[i];
    for (i = 1; i < 128; i += 2)
        out[i] += wavreg1[i] + wavreg2[i];
}
