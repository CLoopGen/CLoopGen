#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern double f[100];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (access every 4th element in multiple passes)
    for (int stride = 0; stride < 4; stride++) {
        for (i = stride; i < 100; i += 4) {
            f[i] = 0;
        }
    }
}
