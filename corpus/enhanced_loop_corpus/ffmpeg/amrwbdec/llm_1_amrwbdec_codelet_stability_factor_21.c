#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern  float *isf;
extern  float *isf_past;
extern int i;
extern float acc;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < 16 - 1; i += 2) {
        acc += (isf[i] - isf_past[i]) * (isf[i] - isf_past[i]);
        if (i + 1 < 16 - 1) {
            acc += (isf[i + 1] - isf_past[i + 1]) * (isf[i + 1] - isf_past[i + 1]);
        }
    }
}
