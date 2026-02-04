#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int *in;
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (backward iteration)
    for (i = 16; i >= 0; i -= 2) {
        if (i + 1 <= 17 && i >= 0) {
            in[i + 1] += in[i];
        }
    }
}
