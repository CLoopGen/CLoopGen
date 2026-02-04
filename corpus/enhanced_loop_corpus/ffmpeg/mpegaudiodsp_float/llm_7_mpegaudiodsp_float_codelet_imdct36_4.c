#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    float prev = in[0];
    for (i = 1; i <= 17; i++) {
        float current = in[i];
        in[i] += prev;
        prev = current;
    }
}
