#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    float *in = input;
    for (i = 0; i < 64; i++) {
        float temp1 = in[i];
        float temp2 = in[255 - i];
        in[i] = temp2;
        in[255 - i] = temp1;
    }
}
