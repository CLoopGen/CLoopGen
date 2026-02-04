#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern int x;
extern  int w2;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 2: Consecutive memory access pattern using a simulated array buffer
    // Introduce local array to demonstrate consecutive accesses
    volatile char buffer[64];
    volatile char *ptr = buffer;
    for (x = 0; x < w2 && x < 64; x++) {
        ptr[x] = (char)(x & 0xFF);  // Sequential write, consecutive access pattern
    }
}
