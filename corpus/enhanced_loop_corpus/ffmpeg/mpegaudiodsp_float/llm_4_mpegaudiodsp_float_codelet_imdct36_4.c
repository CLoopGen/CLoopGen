#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 17; i >= 1; i--) {
        if (in[i - 1] > 0.0f) {
            in[i] += in[i - 1];
        }
    }
}
