#include <stdio.h>

#include <inttypes.h>

#include <stdlib.h>
#include <stddef.h>
extern unsigned char *raxKey;
extern uint64_t bucketKey;

// Variable name mappings to avoid conflicts with system symbols



void loop(){
    // Variant 1: Strided memory access with stride of 2 (access every second element)
    // Simulate reading 6 bytes with striding by using modulo to stay within bounds
    bucketKey = 0;
    for (int i = 0; i < 6; ++i) {
        int index = (i * 2) % 12; // Assume raxKey has at least 12 elements for safety
        bucketKey = (bucketKey << 8) + raxKey[index];
    }
}
