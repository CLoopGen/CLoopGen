#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int i;
extern unsigned char buf[64];
extern  unsigned char xor_table[37];

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Indirect memory access using an index array (simulated via arithmetic)
    int indices[37];
    for (int j = 0; j < 37; j++)
        indices[j] = j;
    for (i = 0; i < 37; i++) {
        int idx = indices[i];  // Simulate indirect access
        buf[8 + idx] ^= xor_table[idx];
    }
}
