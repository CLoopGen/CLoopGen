#include <stdio.h>

#include <inttypes.h>

extern unsigned int x[16];
extern int i;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access (stride of 2)
    for (i = 0; i < 16; i += 2) {
        x[i] = 0;
        if (i + 1 < 16) {
            x[i + 1] = 0;
        }
    }
}
