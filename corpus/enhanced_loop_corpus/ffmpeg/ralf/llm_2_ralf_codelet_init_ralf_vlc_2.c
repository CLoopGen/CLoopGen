#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int counts[17];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 2nd element first, then odd indices)
    for (int stride = 0; stride < 2; stride++) {
        for (i = stride; i <= 16; i += 2) {
            counts[i] = 0;
        }
    }
}
