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
    for (i = 0; i < 32; i++) {
        out[i]           += wavreg1[i]           + wavreg2[i];
        out[i + 32]      += wavreg1[i + 32]      + wavreg2[i + 32];
        out[i + 64]      += wavreg1[i + 64]      + wavreg2[i + 64];
        out[i + 96]      += wavreg1[i + 96]      + wavreg2[i + 96];
    }
}
