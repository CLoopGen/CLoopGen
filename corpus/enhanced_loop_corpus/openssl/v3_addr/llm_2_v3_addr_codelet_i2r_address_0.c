#include <stdio.h>

#include <inttypes.h>

extern unsigned char addr[16];
extern int n;

// Variable name mappings to avoid conflicts with system symbols



void loop() {
    // Variant 1: Strided memory access with step of 4 (simulating reduced comparison frequency)
    // Instead of checking every two consecutive elements, we check every 4th byte in a staggered way
    // This modifies the access pattern to be strided while preserving similar termination logic
    for (n = 16; n > 3 && addr[n - 1] == 0 && addr[n - 4] == 0; n -= 2)
        ;
}
