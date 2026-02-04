#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *input;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    float *in = input;
    float prev = in[0];
    for (i = 0; i < 128; i++) {
        float current = in[255 - i];
        in[255 - i] = prev;
        prev = in[i];
        in[i] = current;
    }
}
