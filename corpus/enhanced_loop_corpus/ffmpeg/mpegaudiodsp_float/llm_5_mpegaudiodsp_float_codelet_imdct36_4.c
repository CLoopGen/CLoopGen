#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 17; i >= 1; i--) {
        if (i % 2 == 0) {
            in[i] += in[i - 1];
        } else {
            in[i] *= 2.0f;
        }
    }
}
