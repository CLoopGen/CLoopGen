#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned int len;
extern unsigned short count[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2, unrolling the loop to access even indices
    for (unsigned int i = 0; i <= 15; i += 2) {
        count[i] = 0;
        if (i + 1 <= 15) {
            count[i + 1] = 0;
        }
    }
    len = 15;
}
