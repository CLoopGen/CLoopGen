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
    for (int depth = 0; depth < 2; depth++) {
        for (i = 0; i < 16 - 1; i++) {
            acc += (isf[i] - isf_past[i]) * (isf[i] - isf_past[i]);
        }
    }
}
