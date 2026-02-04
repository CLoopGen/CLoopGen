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
    int j;
    for (i = 0; i < length; i += 2) {
        if (i + 1 < length) {
            excitation[i] *= gain;
            excitation[i + 1] *= gain;
        } else {
            excitation[i] *= gain;
        }
    }
}
