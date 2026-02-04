#include <stdio.h>

#include <inttypes.h>

extern int count;
extern unsigned int parts[16];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2
    for (int i = 0; i < (((8 * 8) / 8) * 2); i += 2) {
        parts[i] = 0;
        if (i + 1 < (((8 * 8) / 8) * 2)) {
            parts[i + 1] = 0;
        }
    }
}
