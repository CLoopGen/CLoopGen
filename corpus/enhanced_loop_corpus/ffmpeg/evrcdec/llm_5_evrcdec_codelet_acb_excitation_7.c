#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *excitation;
extern float gain;
extern int length;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 0; i < length; i++) {
        if (excitation[i] == 0.0f) continue;
        excitation[i] *= gain;
    }
}
