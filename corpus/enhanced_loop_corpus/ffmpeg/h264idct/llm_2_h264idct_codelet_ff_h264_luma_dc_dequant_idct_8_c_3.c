#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern int temp[16];
extern int16_t *input;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Consecutive memory access with array indices reordered for sequential input reading
    for (i = 0; i < 4; i++) {
        const int offset = 4 * i;
        // Read input in consecutive order to improve spatial locality
        const int a = input[offset + 0];
        const int b = input[offset + 1];
        const int c = input[offset + 2];
        const int d = input[offset + 3];
        
        const int z0 = a + b;
        const int z1 = a - b;
        const int z2 = c - d;
        const int z3 = c + d;
        
        temp[offset + 0] = z0 + z3;
        temp[offset + 1] = z0 - z3;
        temp[offset + 2] = z1 - z2;
        temp[offset + 3] = z1 + z2;
    }
}
