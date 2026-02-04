#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    for (i = 17; i >= 5; i -= 3) {
        in[i] += in[i - 2] * 1.5f;
        in[i - 1] += in[i - 3] * 0.5f;
    }
}
