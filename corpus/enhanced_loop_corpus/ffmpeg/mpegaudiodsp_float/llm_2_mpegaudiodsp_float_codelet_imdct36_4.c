#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern float *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element in reverse)
    for (i = 16; i >= 0; i -= 2) {
        if (i + 2 <= 17)
            in[i + 2] += in[i];
    }
}
