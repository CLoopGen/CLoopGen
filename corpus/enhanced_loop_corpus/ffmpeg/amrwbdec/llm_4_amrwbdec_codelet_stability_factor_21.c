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
    if (isf == NULL || isf_past == NULL) return;
    for (i = 0; i < 15; i++) {
        float diff = isf[i] - isf_past[i];
        if (diff * diff > 1e-6) {
            acc += diff * diff;
        }
    }
}
